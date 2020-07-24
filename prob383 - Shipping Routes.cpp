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
#define sz(x)				(int)x.size()
#define all(x)				(x.begin(), x.end())
#define ms(x,a)				memset(x,a,sizeof(x))
#define rep(i,a,b)			for(int i=(a); i<(b); i++)
#define repC(i,x)			for(int i=0; i<(sz(x)); i++)
#define repIT(it,x)			for(__typeof((x).begin()) it=(x).begin(); it!=x.end(); it++)

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

VI G[31];

int bfs(int src,int des);

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
		freopen("i.txt","w+",stdout);
	#endif // LU_SERIOUS
    int T, M, N, P, maa, cs, pri, ans;
    MSI mp;
    string s1, s2;
    while(si1(T) != EOF){
		cs = 0;
		pf("SHIPPING ROUTES OUTPUT\n");
        while(T--){
			pf("\n");
            mp.clear();
            maa = 0;
            si3(M,N,P);
            rep(i,0,M){
                cin >> s1;
                mp[s1] = maa++;
            }
			rep(i,0,32){
				G[i].clear();
			}
			rep(i,0,N){
				cin >> s1 >> s2;
				G[mp[s1]].pb(mp[s2]);
				G[mp[s2]].pb(mp[s1]);
			}
			pf("DATA SET %2d\n\n",++cs);
			rep(i,0,P){
				cin >> pri >> s1 >> s2;
				ans = bfs(mp[s1],mp[s2]);
				if(ans != -1){
					pf("$%d\n",ans * 100 * pri);
				}else{
					pf("NO SHIPMENT POSSIBLE\n");
				}
			}
        }
        pf("\nEND OF OUTPUT\n");
    }
	return 0;
}

int bfs(int src,int des){
	bitset <32> vis;
	queue<int> q;
	q.push(src);
	vis[src] = true;
	int v;
	int lvl[31] = {0};
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int x: G[v]){
			if(!vis[x]){
				vis[x] = true;
				q.push(x);
				lvl[x] = lvl[v] + 1;
			}
			if(x == des){
				return lvl[x];
			}
		}
	}
	return -1;
}
