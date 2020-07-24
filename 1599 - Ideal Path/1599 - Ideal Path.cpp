#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
vector < pair < int, int > > G[sz];
vector < int > lvl[sz];
vector < int > ans;
int f[sz];
int g[sz];
bool fl[sz];
bool vis[sz];

int main() {
    int n, m;
    while( scanf( "%d %d", &n, &m ) == 2 ) {
        for( int i=0; i<=n; i++ ) {
            G[i].clear();
            lvl[i].clear();
        }
        for( int i=0; i<m; i++ ) {
            int x, y, z;
            scanf( "%d %d %d", &x, &y, &z );
            G[ x ].push_back( { y, z } );
            G[ y ].push_back( { x, z } );
        }
        queue < int > Q;
        fill( vis, vis + n + 1, 0 );
        Q.push( 1 );
        f[1] = 0;
        vis[1] = 1;
        while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            for( auto vv: G[u] ) {
                if( vis[ vv.first ] == false ) {
                    vis[ vv.first ] = true;
                    f[ vv.first ] = f[ u ] + 1;
                    Q.push( vv.first );
                }
            }
        }
        fill( vis, vis + n + 1, 0 );
        Q.push( n );
        g[n] = 0;
        vis[n] = 1;
        while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            for( auto vv: G[u] ) {
                if( vis[ vv.first ] == false ) {
                    vis[ vv.first ] = true;
                    g[ vv.first ] = g[ u ] + 1;
                    Q.push( vv.first );
                }
            }
        }
        ans.clear();
        fill( fl, fl + n + 1, 0 );
        for( int i=1; i<=n; i++ ) if( f[i] + g[i] == f[n] ) fl[i] = 1;
        for( int i=1; i<=n; i++ ) if( f[i] == 0 && fl[i] == 1 ) lvl[0].push_back( i );
        for( int i=0; i<f[n]; i++ ) {
            sort( lvl[i].begin(), lvl[i].end() );
            lvl[i].resize( unique( lvl[i].begin(), lvl[i].end() ) - lvl[i].begin() );
            int min_w = 1 << 30;
            for( const int &v: lvl[i] ) {
                for( const auto &vv: G[v] ) {
                    if( fl[ vv.first ] == 1 && f[ vv.first ] == i + 1 ) {
                        min_w = min( min_w, vv.second );
                    }
                }
            }
            ans.push_back( min_w );
            for( const int &v: lvl[i] ) {
                for( const auto &vv: G[v] ) {
                    if( fl[ vv.first ] == 1 && f[ vv.first ] == i + 1 && min_w == vv.second ) {
                        lvl[i + 1].push_back( vv.first );
                    }
                }
            }
        }
        printf( "%d\n", f[n] );
        for( int i=0; i<ans.size(); i++ ) if( i ) printf( " %d", ans[i] ); else printf( "%d", ans[i] );
        printf( "\n" );
    }
    return 0;
}
