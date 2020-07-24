#include <bits/stdc++.h>
using namespace std;

int minpri[1047], fac[1047][1047], a1[1047], b1[1047];

void pre(){
	for(int i=2; i * i <= 1000; ++i) {
		if(!minpri[i]) { 
	    	for(int j = i * i; j <= 1000; j += i) {
	        	if(!minpri[j]) {
	            	minpri[j] = i;
	            }
    		}
		}
	}

	for(int i=2; i<=1000; ++i) {
	    if(!minpri[i]) {
	        minpri[i] = i;
	    }
	}

	for(int i=2; i<=1000; i++){
		int n = i;
		while(n != 1){
			fac[i][minpri[n]]++;
			n /= minpri[n];
		}
	}

	for(int i=1; i<=1000; i++){
		for(int j=0; j<=i; j++){
			fac[i][j] += fac[i-1][j];
		}
	}
}

void process(int x,int *a){
	for(int i=0; i<=1000; i++){
		a[i] += fac[x][i];
	}
}

int main(){
	pre();
	int n, m, x;
	while(cin >> n >> m && n+m){
		
		memset(a1, 0, sizeof(a1));
		memset(b1, 0, sizeof(b1));

		for(int i=0; i<n; i++){
			cin >> x;
			process(x, a1);
		}
		for(int i=0; i<m; i++){
			cin >> x;
			process(x, b1);
		}

		n = max(n,m);
		bool fl(true);

		for(int i=0; i<=n; i++){
			if(a1[i] != b1[i]){
				fl = false;
				break;
			}
		}

		if(fl){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

	}
    return 0;
}

