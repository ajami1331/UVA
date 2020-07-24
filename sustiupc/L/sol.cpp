#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, cs = 0, n;
	double x, y, l, angle, pi = acos(-1.0);
	cin >> t;
	while(t-- && cin >> n >> l >> x >> y){
		angle = ( 2 * pi ) / n;
		cout << "Case #" << ++cs << ":\n";
		printf("%.6lf %.6lf\n", x, y);
		printf("%.6lf %.6lf\n", x+l, y);
		x += l;
		n -= 2;
		int i = 1;
		while(n--){
			x += cos(i * angle) * l;
			y += sin(i * angle) * l;
			i++;
			printf("%.6lf %.6lf\n", x, y); 
		}
		if(t)
			putchar('\n');
	}
    return 0;
}

