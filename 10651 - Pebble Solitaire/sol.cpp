#include <bits/stdc++.h>
using namespace std;

int dp[1<<13];

bool check(int n,int pos) {
	return n & (1<<pos);
}

bool Check(int n,int pos) {
	return n & (1<<pos);
}

int bit_cnt(int n) {
	int ret = 0;
	while(n) {
		ret += n&1;
		n >>= 1;
	}
	return ret;
}

int recur(int mask) {
	if( dp[mask] != -1)  return dp[ mask ];
	int &ret = dp[ mask ];
	ret = bit_cnt( mask );
	for(int i=0; i<10; i++) {
		if( !check( mask, i ) && check( mask, i+1 ) && check( mask, i+2 ) ) {
			int nxt = mask | (1<<i);
            nxt &= ~( 1<<(i+1) );
            nxt &= ~( 1<<(i+2) );
			ret = min( ret, recur( nxt ) );
		}
		if( check( mask, i ) && check( mask, i+1 ) && !check( mask, i+2 ) ) {
			int nxt = mask | ( 1<<(i+2) );
            nxt &= ~( 1<<(i) );
            nxt &= ~( 1<<(i+1) );
			ret = min( ret, recur( nxt ) );
		}
	}
	return ret;
}

int main() {
	memset( dp, -1, sizeof dp );
	int t, mask;
	char s[12];
	cin >> t;
	while(t-- && cin >> s) {
		mask = 0;
		for(int i=0; i<12; i++) {
			if( s[i] == 'o' ) {
				mask |= (1<<i);
			}
		}
		cout << recur( mask ) << "\n";
	}
	return 0;
}
