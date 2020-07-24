#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int n, ar[21], con[21], hr[21];
int dp[21][21], ans;

int rec( int i, int j ) {
    if( i == n || j == n ) return 0;
    int &ret = dp[i][j];
    if( ~ret ) return ret;
    ret = 0;
    if( con[i] == ar[j] ) ret = 1 + rec( i+1, j+1 );
    else ret = max( rec( i+1, j ), rec( i, j+1 ) );
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    scanf( "%d", &n );
    for( int i=0; i<n; i++ ) {
        scanf( "%d", &ar[i] );
        con[ar[i]-1] = i;
    }
//    for( int i=0; i<n; i++ ) cerr << con[i]+1 << " \n"[ i==n-1 ];
    while( ~scanf( "%d", &hr[0] ) ) {
        for( int i=1; i<n; i++) scanf( "%d", &hr[i] );
        for( int i=0; i<n; i++) ar[ hr[i]-1 ] = i;
//        for( int i=0; i<n; i++ ) cerr << ar[i]+1 << " \n"[ i==n-1 ];
        memset( dp, -1, sizeof dp );
        printf( "%d\n", rec( 0, 0 ) );
    }
    return 0;
}
