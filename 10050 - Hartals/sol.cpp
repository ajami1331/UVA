#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, h[101], d[3666], ans, n, p;
	cin >> t;
	while(t-- && cin >> n >> p) {
		ans = 0;
		for(int i=0; i<p; i++) cin >> h[i];
		memset(d, 0, sizeof(d));
		for(int i=0; i<p; i++) {
			for(int j=1; j<=n; j++) {
				if( j % h[i] == 0 ) {
					d[j] = 1;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(i % 7 == 6 || i % 7 == 0) continue; 
			ans += d[i] == 1;
		}
		cout << ans << "\n";
	}
    return 0;
}

