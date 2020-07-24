#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;

using ll = long long;
const ll mod = 1e9 + 7;

inline int RI() {
    int  ret = 0, flag = 1,ip = getchar();
    for(; ip < 48 || ip > 57; ip = getchar()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

ll big_mod( ll b, ll p ) {
    ll ret = 1;
    for( ; p; p >>= 1 ) {
        if( p&1 ) ret = ( ret * b ) % mod;
        b = ( b * b ) % mod;
    }
    return ret % mod;
}

const int inf = 1e9 + 7;
int ar[105][105];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int n, s, q, x, y, cost, cs = 0;
    while( ~scanf( "%d %d %d", &n, &s, &q ) && n+s+q ) {
        for( int i=1; i<=n; i++ )
            for( int j=1; j<=n; j++ ) ar[i][j] = inf;
        while( s-- ) {
            scanf( "%d %d %d", &x, &y, &cost );
            ar[x][y] = min( cost, ar[x][y] );
            ar[y][x] = ar[x][y];
        }
        for( int via=1; via<=n; via++ ) {
            for( int from=1; from<=n; from++ ) {
                for( int to=1; to<=n; to++ ) {
                    ar[from][to] = min( ar[from][to], max( ar[from][via], ar[via][to] ) );
                }
            }
        }
        if( cs ) printf( "\n" );
        printf( "Case #%d\n", ++cs );
        while( q-- ) {
            scanf( "%d %d", &x, &y );
            if( ar[x][y] == inf ) {
                printf( "no path\n" );
            } else printf( "%d\n", ar[x][y] );
        }
    }
    return 0;
}
