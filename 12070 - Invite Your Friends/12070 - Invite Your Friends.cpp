#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int inf = 1 << 28;
int n, f, t, mn, sm, disf, idx, idy, cs = 0;
int dirx[] = { 0,  0, 1, -1 };
int diry[] = { 1, -1, 0,  0 };
int ar[26][26];
int dist[26][26][26];

struct fff{
    int x, y;
} fr[6];

struct node{
    int x, y, cost, time;
    bool operator<(const node &other) const{
        return other.cost < cost;
    }
};

void reset() {
    for( int i=0; i<n; i++ )
        for( int j=0; j<n; j++ )
            for( int k=0; k<=t; k++ )
                dist[i][j][k] = inf;
}

void dijkstra( int x, int y ) {
    node nd;
    int nx, ny, ncst, nt;
    priority_queue < node > Q;
    Q.push( { x, y, 0, 0 } );
    dist[x][y][0] = 0;
    while( !Q.empty() ) {
        nd = Q.top();
        Q.pop();
        for( int i=0; i<4; i++ ) {
            nx = nd.x + dirx[i];
            ny = nd.y + diry[i];
            nt = nd.time + 1;
            if( nt > t ) continue;
            if( nx < 0 || nx >= n or ny < 0 or ny >= n ) continue;
            ncst = nd.cost + ar[nx][ny];
            if( dist[nx][ny][nt] > ncst ) {
                dist[nx][ny][nt] = ncst;
                Q.push( { nx, ny, ncst, nt } );
            }
        }
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    while( ~scanf( "%d %d %d", &n, &f, &t ) and n+f+t ) {
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                scanf( "%d", &ar[i][j] );
            }
        }
        for( int i=0; i<f; i++ ) {
            scanf( "%d %d", &fr[i].x, &fr[i].y );
        }
        mn = inf;
        bool fl;
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                reset();
                dijkstra( i, j );
                sm = 0;
                fl = 1;
                for( int k=0; k<f; k++ ) {
                    disf = inf;
                    for( int l=0; l<=t; l++ ) {
                        disf = min( disf, dist[fr[k].x][fr[k].y][l] );
                    }
                    sm += disf;
                }
                if( sm < mn ) {
                    mn = sm;
                    idx = i;
                    idy = j;
                }
            }
        }
        if( mn >= inf ) printf( "Case #%d: Impossible.\n", ++cs );
        else printf( "Case #%d: Selected city (%d,%d) with minimum cost %d.\n", ++cs, idx, idy, mn );
    }
    return 0;
}
