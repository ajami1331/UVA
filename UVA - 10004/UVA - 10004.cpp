#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;

vector < int > G[sz];
int color[sz];

int dfs( int u, int c ) {
        color[u] = c;
        int ans = 0;
        for( const int& v: G[u] ) if( color[v] == 0 ) {
                ans |= dfs( v, c == 1 ? 2 : 1 );
        } else if( color[v] == c ) ans |= 1;
        return ans;
}

int main() {

        int n, m;

        while( scanf( "%d", &n ) == 1 && n > 0 ) {

                scanf( "%d", &m );

                for( int i=0; i<n; i++ ) G[i].clear();

                while( m-- ) {

                        int x, y;

                        scanf( "%d %d", &x, &y );

                        G[ x ].push_back( y );
                        G[ y ].push_back( x );
                }

                fill( color, color + n, 0 );

                int ans = 0;

                for( int i=0; i<n; i++ ) if( color[i] == 0 ) {
                        ans |= dfs( i, 1 );
                }

                puts( ans ? "NOT BICOLORABLE." : "BICOLORABLE." );
        }

        return 0;
}