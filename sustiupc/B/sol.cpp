#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

const LL mod = (1e9) + 7; 
LL n, six, two;

LL modPow(LL a,LL pow){
    LL ret = 1;
    for(; pow; pow>>=1){
        if(pow&1) ret = (ret * a) % mod;
        a = (a * a) % mod;
    }
    return ret;
}

LL cal1() {
	LL ret = (  n  *  ( n + 1 ) ) % mod;
	ret *= ( n + n + 1 );
	ret %= mod;
	ret *= six;
	return ret % mod;
}

LL cal2() {
	LL ret = ( n * ( n + 1 ) ) % mod;
	ret *= two;
	return ret % mod;
}

int main(){
	six = modPow(6,mod-2), two = modPow(2,mod-2);
	int t, cs = 0;
	scanf("%d", &t);
	while(t-- && ~scanf("%lld", &n)){
		printf("Case %d: ", ++cs);
		printf("%lld\n", ( cal1() + cal2() ) % mod);
	}
    return 0;
}

