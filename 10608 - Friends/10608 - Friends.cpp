#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Disjoint_Set {
    int n;
    vector < int > par, cnt, rank;

    Disjoint_Set( int n ) : n(n), rank(n), par(n), cnt(n) {}

    void make_set() {
        for(int i=0; i<n; i++) {
            par[i] = i;
            cnt[i] = 1;
            rank[i] = 0;
        }
    }

    int find_rep( int x ) {
        if(x != par[ x ]) {
            par[ x ] = find_rep( par[ x ] );
        }
        return par[ x ];
    }

    int union_( int u, int v ) {
        if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
            if( rank[ u ] < rank[ v ] ) {
                cnt[ v ] += cnt[ u ];
                par[ u ] = par[ v ];
                return cnt[v];
            } else {
                rank[ u ] = max( rank[ u ], rank[ v ] + 1 );
                cnt[ u ] += cnt[ v ];
                par[ v ] = par[ u ];
            }
        }
        return cnt[u];
    }
};

map < string, int > mp;

const int mxn = 1e5 + 10;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    Disjoint_Set dsu( mxn );
    string a, b;
    int k, t;
    scanf( "%d", &t );
    while( t-- and ~scanf( "%d", &m ) ) {
        dsu.make_set();
        mp.clear();
        k = 0;
        for( int i=0; i<m; i++ ) {
            cin >> a >> b;
            if( mp.find( a ) == mp.end() ) {
                mp[a] = k++;
            }
            if( mp.find( b ) == mp.end() ) {
                mp[b] = k++;
            }
            printf( "%d\n", dsu.union_( mp[a], mp[b] ) );
        }
    }
    return 0;
}
