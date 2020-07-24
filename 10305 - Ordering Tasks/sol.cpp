#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector <int> G[N];
bool vis[N];
stack <int> ans;

void top_sort(int u) {
	vis[u] = true;
	for(int v: G[u]) {
		if(!vis[v]) {
			top_sort(v);
		}
	}
	ans.push(u);
}

int main() {
	int n, e, u, v; 
	while(cin >> n >> e && n+e) {
		for(int i=0; i<=n; i++) {
			G[i].clear();
		}
		while(e--) {
			cin >> u >> v;
			G[u].push_back(v);
		}
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++)
			if(!vis[i])
				top_sort(i);
		while(!ans.empty()) {
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << "\n";
	}
    return 0;
}

