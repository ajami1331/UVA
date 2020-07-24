#include <bits/stdc++.h>
using namespace std;

int p, t;
bool vis[1001];

vector<int> G[1001], gT[1001];
map<string,int> mp;
stack < int > top_sorted;

int kosaraju();
void top_sort();
void dfs_kosaraju(int u);
void dfs_top_sort(int u);

int main() {
	string u, v, s1, s2;
	while(cin >> p >> t && p+t) {
		int k = 0;
		mp.clear();
		for(int i=0; i<=p; i++) G[i].clear(), gT[i].clear();
		for(int i=0; i<p; i++) {
			
			cin >> s1 >> s2;
			u = s1 + s2;
			
			if(!mp[ u ]) mp[ u ] = ++k;
		}
		for(int i=0; i<t; i++) {
			
			cin >> s1 >> s2;
			u = s1 + s2;
			
			cin >> s1 >> s2;
			v = s1 + s2;
		
			G[ mp[ u ] ].push_back( mp[ v ] );
			gT[ mp[ v ] ].push_back( mp[ u ] );
		}
		cout << kosaraju() << "\n";
	}	
    return 0;
}

int kosaraju() {
	memset( vis, false, sizeof(vis) );
	top_sort();
	int u, ret = 0;
	memset( vis, false, sizeof(vis) );
	while(!top_sorted.empty()) {
		u = top_sorted.top();
		top_sorted.pop();
		if(!vis[u])
			dfs_kosaraju( u ), ret++;
	}
	return ret;
}

void top_sort() {
	for(int i=1; i<=p; i++) {
		if(!vis[i]) {
			dfs_top_sort(i);
		}
	}
}

void dfs_top_sort(int u) {
	vis[u] = true;
	for(int v: G[u]) {
		if(!vis[v]) {
			dfs_top_sort( v );
		}
	}
	top_sorted.push( u );
}

void dfs_kosaraju(int u) {
	vis[u] = true;
	for(int v: gT[u]) {
		if(!vis[v]) {
			dfs_kosaraju( v );
		}
	}
}