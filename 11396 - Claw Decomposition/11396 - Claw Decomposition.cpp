#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector < int > G[305];
int vis[305];

bool dfs( int u, int c ) {
    vis[u] = c;
    bool ret = 1;
    for( int v: G[u] ) {
        if( !vis[v] ) {
            ret &= dfs( v, c == 1 ? 2 : 1 );
        } else if( vis[v] == c ) ret = 0;
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif
    int v, a, b;
    bool fl;
    while( scanf( "%d", &v ) && v ) {
        for( int i=0; i<=v; i++ ) G[i].clear();
        memset( vis, 0, sizeof vis );
        while( scanf( "%d %d", &a, &b ) && a+b ) {
            G[a].push_back( b );
            G[b].push_back( a );
        }
        fl = 1;
        for( int i=1; i<=v; i++ ) {
            if( !vis[i] ) {
                fl &= dfs( i, 1 );
            }
        }
        printf( "%s\n", fl ? "YES" : "NO" );
    }
    return 0;
}
