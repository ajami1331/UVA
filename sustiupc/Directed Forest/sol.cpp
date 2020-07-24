#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
vector< int > G[MAX+7];
bool vis[MAX+7];
int len[MAX+7];

int dfs(int x) {
	vis[x] = true;
	int ret = 1;
	if(!G[x].size()) return 1;
	for (int k: G[x]){
		if(!vis[k]) {
			len[k] = max(dfs(k),len[k]);
			ret = max(ret, len[k]);
		} else {
			ret = max(ret, len[k]);
		}
	}

	return ret+1;
}

int main(){
	int t, n, e, ans, cs = 0,u, v;;
	cin >> t;
	while(t-- && ~scanf("%d %d", &n, &e)) {
		for(int i=0; i<=n; i++) G[i].clear(), vis[i] = 0, len[i] = 0;
		for(int i=0; i<e; i++){
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		ans = 0;
		for(int i=0; i<=n; i++) {
			if(!vis[i]) {
				len[i] = max(len[i], dfs(i));
			}
			ans = max(len[i], ans);
		}
		cout << "Case " << ++cs << ": " << ans << "\n";
	}
    return 0;
}

