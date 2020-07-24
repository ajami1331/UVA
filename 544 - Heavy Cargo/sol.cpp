#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int INF = -1;
int G[205][205];
map <string, int> mp;

int main(){
	int n, r, cost, id, cs = 0;
	string s1, s2;
	while(cin >> n >> r && n+r) {
		mp.clear(); id = 0;
		
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				G[i][j] = INF ;

		while(r--) {
			cin >> s1 >> s2 >> cost;
			
			if(!mp[s1]) mp[s1] = ++id;
			if(!mp[s2]) mp[s2] = ++id;

			G[ mp[ s1 ] ][ mp[ s2 ] ] = cost;
			G[ mp[ s2 ] ][ mp[ s1 ] ] = cost;
		}

		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					G[i][j] = max( G[i][j], min( G[i][k] , G[k][j] ) );
	
		cin >> s1 >> s2;
		
		printf("Scenario #%d\n%d tons\n\n", ++cs, G[ mp[ s1 ] ][ mp[ s2 ] ]);
	}
    return 0;
}

