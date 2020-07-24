#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int ar[1005];
vector < int > G[1005];
int t, cs, n, ans, h;

void rec( int u, int cn, int par ) {
    if( ar[u]&1 ) h ^= cn;
    for( int v: G[u] ) {
        if( v == par ) continue;
        rec( v, cn+1, u );
    }
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // CLown1331
    int u, v;
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d", &n );
        ans = 0;
        for( int i=1; i<=n; i++ ) G[i].clear();
        for( int i=1; i<=n; i++ ) scanf( "%d", &ar[i] );
        for( int i=1; i<n; i++ ) {
            scanf( "%d %d", &u, &v );
            G[u].push_back( v );
            G[v].push_back( u );
        }
        for( int i=1; i<=n; i++ ) {
            h = 0;
            rec( i, 0, -1 );
            if( !h ) ans++;
        }
        printf( "Case %d: %d\n", cs, ans );
    }
    return 0;
}
