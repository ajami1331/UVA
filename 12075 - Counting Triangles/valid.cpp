#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
long long n, m, dp[N][N];
int cas;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void init() {
	cas = 0;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= 1000; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + gcd(i, j) - 1;
	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= 1000; j++)
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
}

long long C(long long n, long long m) {
	if (m > n) return 0;
	m = min(m, n - m);
	long long ans = 1;
	for (long long i = 0; i < m; i++)
		ans = ans * (n - i) / (i + 1);
	return ans;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "val.txt", "w+", stdout );
    #endif // LU_SERIOUS
    init();
    for( int i=0; i<=10; i++ )
        for( int j=0; j<=10; j++ )  cout << dp[i][j] << " \n"[ j==10 ];
	while (~scanf("%lld%lld", &n, &m) && n || m) {
		n++; m++;
		cout << dp[n - 1][m - 1] * 2 << " ";
		printf("Case %d: %lld\n", ++cas, C(n * m, 3) - n * C(m, 3) - m * C(n, 3) - dp[n - 1][m - 1] * 2);
 	}
	return 0;
}
