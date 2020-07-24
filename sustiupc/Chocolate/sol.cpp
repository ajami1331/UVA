#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

bitset <MAX> a, b, c;

int main(){
	int t, l, r, s, x, sa, sb, sc, ab, ac, bc, abc, cs = 0, mx;
	cin >> t;
	while(t-- && ~scanf("%d %d %d", &l, &r, &s)) {
		sa = 0, sb = 0, sc = 0, ab = 0, ac = 0, bc = 0, abc = 0;

		a.reset(); b.reset(); c.reset();

		mx = -1;
		for(int i=0; i<l; i++){
			scanf("%d", &x);
			if(!a[x]){
				sa++;
			}
			mx = max(mx, x);
			a[x] = true;
		}
		for(int i=0; i<r; i++){
			scanf("%d", &x);
			if(!b[x]){
				sb++;
			}
			mx = max(mx, x);
			b[x] = true;
		}
		for(int i=0; i<s; i++){
			scanf("%d", &x);
			if(!c[x]){
				sc++;
			}
			mx = max(mx, x);
			c[x] = true;
		}
		for(x=0; x<=mx; x++){
			if(a[x] && b[x] && c[x]) abc++;
			if(a[x] && !b[x] && c[x]) ac++;
			if(a[x] && b[x] && !c[x]) ab++;
			if(!a[x] && b[x] && c[x]) bc++;
		}
		//cout << abc << " " << ab << " " << ac << " " << bc << "\n";
		printf("Case #%d:\n", ++cs);
		printf("%d %d\n", sa-abc-ab-ac, bc);
		printf("%d %d\n", sb-abc-ab-bc, ac);
		printf("%d %d\n", sc-abc-ac-bc, ab);
	}
    return 0;
}

