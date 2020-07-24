#include <bits/stdc++.h>
using namespace std;
using pii = pair < int, int >;
using ll = long long int;
const int mx = 1e3;
ll dp[mx+1][mx+1];

ll nc3( ll n ) {
    if( n < 3 ) return 0;
    return ( n * ( n - 1 ) * ( n - 2 ) ) / 6;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int n, m;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= 1000; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + __gcd(i, j) - 1;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= 1000; j++)
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    ll ans, cs = 0;
    while( ~scanf( "%d %d", &n, &m ) && n+m ) {
        n++;
        m++;
        ans = nc3( n * m ) - nc3( n ) * m - nc3( m ) * n - dp[n-1][m-1] * 2;
        printf( "Case %lld: %lld\n", ++cs, ans );
    }
    return 0;
}

