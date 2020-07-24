#include <bits/stdc++.h>
using namespace std;

int calc(int n) {
	int cur = 1, dcount = 1;
	while(cur % n) {
		cur = (cur * 10 + 1) % n;
		dcount++;
	}
	return dcount;
}

int main() {
	int n;
	while(cin >> n) {
		cout << calc(n) << "\n";
	}
    return 0;
}

