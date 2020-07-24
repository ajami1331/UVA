#include <bits/stdc++.h>
using namespace std;

int par[27];
vector <int> vertices;
map <int,int> cal;

int fi(int a){
	return a == par[a] ? a : par[a] = fi(par[a]);
}

void uni(int u,int v){
	if( (u = fi(u)) != (v = fi(v)) ){
		par[v] = par[u];
	}
}

int main(){
	string s;
	int t, acorn, tree;
	cin >> t;
	while(t--){
		for(int i=0; i<26; i++) par[i] = i;
		vertices.clear(), cal.clear();
		while(cin >> s && s[0] != '*'){
			uni(s[1]-'A',s[3]-'A');
		}
		cin >> s;
		for(int i=0; i<s.size(); i++){
			if(isalpha(s[i])){
				vertices.push_back(s[i]-'A');
			}
		}
		acorn = 0, tree = 0;
		for(int x: vertices){
			cal[fi(x)]++;
		}
		for(auto x: cal) x.second == 1 ? acorn++ : tree++ ;
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
	return 0;
}
