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
#define MAX 1000015
int ar[MAX+25];
char str[MAX+25];

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	int n, x, y, csn = 0;
	while(sf("%s",str) != EOF){
		if(strcmp(str,"\n") == 0){
			break;
		}
		ar[0] = str[0]-'0';
		for(int i=1; str[i]!='\0'; i++){
			ar[i] = 0;
			ar[i] = str[i]-'0';
			ar[i] += ar[i-1];
		}
		si1(n);
		pf("Case %d:\n",++csn);
		for(int i=0; i<n; i++){
			si2(x,y);
			if(x>y){
				swap(x,y);
			}
			if(str[x] == '0'){
				if(ar[x] == ar[y]){
					pf("Yes\n");
				}else{
					pf("No\n");
				}
			}else{
				if(ar[y]-ar[x] == y-x){
					pf("Yes\n");
				}else{
					pf("No\n");
				}
			}
		}
	}
	return 0;
}

