#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <bitset>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <fstream>
#include <limits>
#include <new>
#include <memory>

using namespace std;

#define pb					push_back
#define F					first
#define S					second
#define EPS					1e-9
#define sf					scanf
#define pf					printf
#define si1(x)				scanf("%d",&x)
#define si2(x,y)			scanf("%d %d",&x,&y)
#define si3(x,y,z)			scanf("%d %d %d",&x,&y,&z)
#define sd1(x)				scanf("%lf",&x)
#define sd2(x,y)			scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)			scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)				scanf("%lld",&x)
#define sl2(x,y)			scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)			scanf("%lld %lld %lld",&x,&y,&z)
#define sz(x)				(int)(x).size()
#define all(x)				(x).begin(), (x).end()
#define ms(x,a)				memset(x,a,sizeof(x))
#define REP(i,a,b)			for(int i=(a); i<(b); i++)
#define REPC(i,x)			for(int i=0; i<(sz(x)); i++)
#define REPIT(it,x)			for(__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)

typedef long long int		LL;
typedef pair<int,int>		PII;
typedef vector<int>			VI;
typedef vector<LL>			VL;
typedef vector<string>		VS;
typedef vector<char>		VC;
typedef vector<bool>		VB;
typedef vector<PII>			VII;
typedef map<string,int>		MSI;
typedef map<int,int>		MII;
typedef map<char,int>		MCI;
typedef map<int,string>		MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }
template<typename T> inline T powa(T x,T p){
	if(!p)
		return 1;
	else
		if(p&1)
			return x*powa(x,p-1);
		else{
			T ret = powa(x,p>>1);
			return ret*ret;
		}
}
int n, si;
VI par;
MSI mapa;
MIS mapp;

vector<VI> G;
vector<pair<string,string>> VPP;

bool bfs(int src,int des);

void print(int a,int b);

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w+",stdout);
	#endif // LU_SERIOUS
	int kk, cs = 0;
	string s1, s2;
	while(si1(n) != EOF){
		mapa.clear();
		mapp.clear();
		VPP.clear();
		kk = 1;
		REP(i,0,n){
			cin >> s1 >> s2;
			VPP.pb(pair<string,string>(s1,s2));
			if(mapa.find(s1) == mapa.end()){
				mapp[kk] = s1;
				mapa[s1] = kk++;
			}
			if(mapa.find(s2) == mapa.end()){
				mapp[kk] = s2;
				mapa[s2] = kk++;
			}
		}
		si = mapa.size();
		si++;
		G = vector<VI>(si+1,VI());
		for(auto x: VPP){
			s1 = x.F;
			s2 = x.S;
			G[mapa[s1]].pb(mapa[s2]);
			G[mapa[s2]].pb(mapa[s1]);
		}
		cin >> s1 >> s2;
		if(cs){
			cout << "\n";
		}
		if(bfs(mapa[s1],mapa[s2])){
			print(mapa[s2],mapa[s1]);
		}else{
			cout << "No route\n";
		}
		cs++;
	}
	return 0;
}

bool bfs(int src,int des){
	vector<bool> vis(si+1,false);
	par = VI(si+1,-1);
	vis[src] = true;
	queue<int> q;
	q.push(src);
	par[src] = src;
	int v;
//	cout << src << " " << des << "\n";
//	cout << mapp[des] << " " << mapp[src] << "\n";
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int x: G[v]){
			if(!vis[x]){
				vis[x] = true;
				par[x] = v;
				q.push(x);
			}
			if(x == des){
				return true;
			}
		}
	}
	return false;
}

void print(int a,int b){
	if(a == b) return;
	print(par[a],b);
	cout << mapp[par[a]] << " " << mapp[a] << "\n";
}
