#include <bits/stdc++.h>
using namespace std;

string s[1001];

int main() {
	int t, n, cs = 0, dif;
	string co;
	cin >> t;
	while(t-- &&  cin >> n) {
		for(int i=0; i<n; i++) cin >> s[i];
		cin >> co;
		cout << "Case " << ++cs << ":\n";
		for(int i=0; i<n; i++) {
			dif = 0;
			for(int j=0; j<co.size(); j++) {
				dif += s[i][j] != co[j];
			}
			if(dif <= 1) cout << s[i] << "\n";
		}
	}
    return 0;
}

