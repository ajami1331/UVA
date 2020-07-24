#include <bits/stdc++.h>

using namespace std;

#define pb                              push_back
#define F                               first
#define S                               second
#define EPS                             1e-9
#define sf                              scanf
#define pf                              printf
#define si1(x)                          scanf("%d",&x)
#define si2(x,y)                        scanf("%d %d",&x,&y)
#define si3(x,y,z)                      scanf("%d %d %d",&x,&y,&z)
#define sd1(x)                          scanf("%lf",&x)
#define sd2(x,y)                        scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)                      scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)                          scanf("%lld",&x)
#define sl2(x,y)                        scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)                      scanf("%lld %lld %lld",&x,&y,&z)
#define sz(x)                           (int)(x).size()
#define all(x)                          (x).begin(), (x).end()
#define rall(x)                         (x).rbegin(), (x).rend()
#define ms(x,a)                         memset(x,a,sizeof(x))
#define REP(i,a,b)                      for(int i=(a); i<(b); i++)
#define REV(i,a,b)                      for(int i=(a); i>=(b); i--)
#define REPS(i,a,b,step)				for(int i=(a); i<(b); i+=step)
#define REVS(i,a,b,step)				for(int i=(a); i>=(b); i-=step)
#define REPIT(it,x)                     for(__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)

typedef long long int                   LL;
typedef pair<int,int>                   PII;
typedef vector<int>                     VI;
typedef vector<LL>                      VL;
typedef vector<string>                  VS;
typedef vector<char>                    VC;
typedef vector<bool>                    VB;
typedef vector<PII>                     VII;
typedef map<string,int>                 MSI;
typedef map<int,int>                    MII;
typedef map<char,int>                   MCI;
typedef map<int,string>                 MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }

LL modPow(LL a,LL pow,LL mod){
    if(!pow) return 1;
    else
        if(pow&1) return ( a * modPow(a,pow-1,mod) ) % mod;
        else{
            LL ret = modPow(a,pow>>1,mod)  % mod;
            return (ret * ret) % mod;
        }
}

LL modINV(LL a,LL M){
    return modPow(a,M-2,M);
}

const int MAXN = (3e4) + 10;
LL dp[15][MAXN];
int coin[] = {0,5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
#ifdef LU_SERIOUS
    freopen("in.txt","r",stdin);
//    freopen("i.txt","w+",stdout);
#endif // LU_SERIOUS
	double mk;
	string s;
	LL n;
	while(cin >> s){
		stringstream ss;
		ss << s;
		ss >> mk;
		n = 0;
		REP(i,0,sz(s)){
			if(s[i] == '.')	continue;
			else{
				n *= 10;
				n += s[i]-'0';
			}
		}
		if(!n) break;
		REP(i,0,n+1){
			dp[0][i] = 0;
		}
		REP(i,0,12){
			dp[i][0] = 1;
		}
		REP(j,1,n+1){
			REP(i,1,12){
				dp[i][j] = dp[i-1][j];
				if(j >= coin[i]){
					dp[i][j] += dp[i][j-coin[i]];
				}
			}
		}
		pf("%*.2lf%*lld\n", 6, mk, 17, dp[11][n]);
	}
    return 0;
}

