#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = (1e9) + 7;

int main(){
	long long t, n, ar[101], an, cs = 0;
	cin >> t;
	while(t-- && cin >> n) {
		an = 1;
		for(int i=0; i<n; i++) cin >> ar[i];
		sort(ar, ar+n);
		for(int i=0; i<n; i++) {
			if (ar[i] < i){
				an = 0; 
				break;
			}
			an *= ( ar[i] - i );
			an %= mod;
		}
		if(an <= 0) an = 0;
		cout << "Case " << ++cs << ": " << an << "\n";
	}
    return 0;
}

