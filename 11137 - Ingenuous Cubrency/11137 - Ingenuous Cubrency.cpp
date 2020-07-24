#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long int;
const int mod = 1e9 + 7;
int coins[24];
ull dp[24][10005];
int n;

ull rec( int i, int j ) {
    if( i == 22 ) {
        return !j;
    }
    if( ~dp[i][j] ) return dp[i][j];
    ull ret1 = 0, ret2 = 0;
    if( j - coins[i] >= 0 ) ret1 = rec( i, j - coins[i] );
    ret2 = rec( i+1, j );
    return dp[i][j] = ret1 + ret2;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    for( int i=1; i<=21; i++ ) coins[i] = i * i * i;
    memset( dp, -1, sizeof dp );
    while( ~scanf( "%d", &n ) ) {
        printf( "%llu\n", rec( 1, n ) );
    }
    return 0;
}

