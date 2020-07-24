#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int x[91], y[91], z[91], dp[91], n, cs, ans;

int rec( int pos ) {
    if( ~dp[pos] ) return dp[pos];
    int &ret = dp[pos];
    ret = 0;
    for( int i=0; i<n+n+n; i++ ) {
        if( ( x[i] < x[pos] && y[i] < y[pos] ) || ( y[i] < x[pos] && x[i] < y[pos] ) ) {
            ret = max( ret,  z[i] + rec( i ) );
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    while( ~scanf( "%d", &n ) && n ) {
        for( int i=0; i<n; i++ ) {
            scanf( "%d %d %d", &x[i], &y[i], &z[i] );
            x[ i+n ] = y[ i ];
            y[ i+n ] = z[ i ];
            z[ i+n ] = x[ i ];
            x[ i+n+n ] = y[ i+n ];
            y[ i+n+n ] = z[ i+n ];
            z[ i+n+n ] = x[ i+n ];
        }
        ans = 0;
        memset( dp, -1, sizeof dp );
        for( int i=0; i<n+n+n; i++ ) ans = max( z[i]+rec( i ), ans );
        printf( "Case %d: maximum height = %d\n", ++cs, ans );
    }
    return 0;
}
