#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m1, m2, h, bk, ar[201];
	for (int i=1; i<=200; i++) {
		n = i;
		m1 = 0;
		bk = n;
		h = 0;
		while (n) {
			m1 += n;
			h += n % 3;
			n /= 3;
			n += h / 3;
			h %= 3;
		}
		h = 1;
		m2 = 0;
		n = bk;
		while (n) {
			m2 += n;
			h += n % 3;
			n /= 3;
			n += h / 3;
			h %= 3;
		}
		ar[i] = h ? max(m1,m2) : m1 ; 
	}
	while (~scanf("%d", &n)) {
		printf("%d\n", ar[n]);
	}
    return 0;
}

