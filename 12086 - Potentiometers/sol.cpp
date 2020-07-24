#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
int tree[MAX+7], ar[MAX+7];

void update(int val,int x,int n) {
	for(; x<=n; x+=(x&-x)) {
		tree[x] += val;
	}
}

int query(int x) {
	int ret = 0;
	for(; x; x-=(x&-x)) {
		ret += tree[x];
	}
	return ret;
}

int query(int x,int y) {
	return query( y ) - query( x-1 );
}

void init(int n) {
	memset( tree, 0, sizeof tree );
	for(int i=1; i<=n; i++) {
		update( ar[i], i, n );
	}
}

int main() {
	int n, x, y, cs = 0;
	string s;
	while( ~scanf("%d", &n) && n ) {
		if(cs) putchar('\n');
		printf("Case %d:\n", ++cs);
		for(int i=1; i<=n; i++) {
			scanf("%d", &ar[i]);
		}
		init( n );
		while(cin >> s && s != "END") {
			cin >> x >> y;
			if(s == "S") {
				update( -ar[x], x, n );
				update( y, x, n );
				ar[x] = y;
			} else {
				cout << query( x, y ) << "\n";
			}
		}
	}
    return 0;
}
