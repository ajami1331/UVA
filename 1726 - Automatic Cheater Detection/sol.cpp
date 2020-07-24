#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, q, x, y, nl[11], le[11], ans, ha;
	char c;
	scanf("%d", &t);
	while(t-- && ~scanf("%d", &q)) {
		for(int i=0; i<=10; i++) le[i] = 0, nl[i] = 0;
		while(q--) {
			scanf("%d %d %c", &x, &y, &c);
			if(y == 1 && c == 'c') {
				le[x]++;
			}
			if(y == 0 && c == 'i') {
				nl[x]++;
			}
		}
		ans = 0;
		for(int i=0; i<=10; i++) {
			ha = 0;
			for(int j=0; j<i; j++) {
				ha += nl[j];
			}
			ans += ha * le[i];
		}
		cout << ans << "\n";
	}
    return 0;
}

