#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
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
#include <iterator>
#include <sstream>
#include <fstream>

using namespace std;

#define pb				push_back
#define F				first
#define S				second
#define EPS				1e-9
#define sf				scanf
#define pf				printf
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
typedef vector<int>		VI;
typedef vector<LL>		VL;
typedef vector<string>		VS;
typedef vector<char>		VC;
typedef vector<bool>		VB;
typedef vector<PII>		VII;
typedef map<string,int>		MSI;
typedef map<int,int>		MII;
typedef map<char,int>		MCI;
typedef map<int,string>		MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }
LL bigPow(LL a,LL p,LL mod){
    if(!p)
	return 1;
    if(p & 1)
	return ( ( a % mod ) * ( bigPow(a,p-1,mod) % mod ) );
    else{
	LL ret = bigPow(a,p>>1,mod);
	return ( ret * ret ) % mod;
    }
}
VS str_tok(string s){
    stringstream ss(s);
    string s1;
    VS ret;
    while(ss >> s1){
	ret.pb(s1);
    }
    return ret;
}
VS str_tok(char *str){
    VS ret;
    string s = "";
    for(int i=0; str[i]; i++){
	if(str[i] == ' '){
	    if(!s.empty())
		ret.pb(s);
	    s = "";
	}
	else{
	    s += str[i]; 
	}
    }
    return ret;
}
int dp[10002];

int main(){
#ifdef LU_SERIOUS
    freopen("homer.txt","r",stdin);
#endif // LU_SERIOUS
    int k[2] ,t, beer;
    while(si3(k[0],k[1],t) != EOF){
	ms(dp,-1);
	dp[0] = 0;
	for(int i=0; i<2; i++){
	    for(int j=k[i]; j<=t; j++){
		if(dp[j-k[i]] != -1){
		    dp[j] = Max(dp[j], dp[j-k[i]]+1);
		}
	    }
	}
	beer = 0;
	for(int i=t; i>=0; i--){
	    if(dp[i] != -1){
		break;
	    }
	    beer++;
	}
	if(!beer)
	    cout << dp[t] << "\n";
	else
	    cout << dp[t-beer] << " " << beer << "\n";
    }
    return 0;
}

