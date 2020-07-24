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

LL Pow(LL a,LL pow){
	LL ret = 1;
	for(; pow; pow>>=1){
		if(pow&1) ret = (ret * a);
		a = (a * a);
	}
	return ret;
}

LL modPow(LL a,LL pow,LL mod){
	LL ret = 1;
	for(; pow; pow>>=1){
		if(pow&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

LL modINV(LL a,LL M){
    return modPow(a,M-2,M);
}

VI tw,fo,si,ei;
void cal(){
	int n;
	REP(i,0,10){
		REP(j,0,10){
			n = i * 10 + j;
			if(n == sqaa(i+j)){
				tw.pb(n);
			}
		}
	}
	REP(i,0,100){
		REP(j,0,100){
			n = i * 100 + j;
			if(n == sqaa(i+j)){
				fo.pb(n);
			}
		}
	}
	REP(i,0,1000){
		REP(j,0,1000){
			n = i * 1000 + j;
			if(n == sqaa(i+j)){
				si.pb(n);
			}
		}
	}
	REP(i,0,10000){
		REP(j,0,10000){
			n = i * 10000 + j;
			if(n == sqaa(i+j)){
				ei.pb(n);
			}
		}
	}
}

int main(){
#ifdef LU_SERIOUS
    freopen("in.txt","r",stdin);
#endif // LU_SERIOUS
	cal();
	int n;
	while(~si1(n)){
		if(n == 2){
			for(int x: tw){
				pf("%02d\n",x);
			}
		}
		if(n == 4){
			for(int x: fo){
				pf("%04d\n",x);
			}
		}
		if(n == 6){
			for(int x: si){
				pf("%06d\n",x);
			}
		}
		if(n == 8){
			for(int x: ei){
				pf("%08d\n",x);
			}
		}
	}
	return 0;
}

