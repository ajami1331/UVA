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

#define pb		push_back
#define F		first
#define S		second
#define sf 		scanf
#define pf		printf
#define si1(x)		scanf("%d",&x)
#define si2(x,y)	scanf("%d %d",&x,&y)
#define si3(x,y,z)	scanf("%d %d %d",&x,&y,&z)
#define sd1(x)		scanf("%lf",&x)
#define sd2(x,y)	scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)	scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)		scanf("%lld",&x)
#define sl2(x,y)	scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)	scanf("%lld %lld %lld",&x,&y,&z)

typedef long long int	LL;
typedef pair<int,int>	PII;
typedef vector<int>		VI;
typedef vector<string>	VS;
typedef vector<char>	VC;
typedef vector<bool>	VB;
typedef vector<PII>		VII;
typedef map<string,int>	MSI;
typedef map<int,int>	MII;
typedef map<char,int>	MCI;
typedef map<int,string>	MIS;

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

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	int month, loan_int, mnth, ans;
	double pay, loan_amnt, _val, loa_in[101], inte;
	while(si1(month)==1 && month>0){
		sd2(pay, loan_amnt);
		si1(loan_int);
		for(int i=1; i<month; i++){
			loa_in[i] = -1;
		}
		for(int i=0; i<loan_int; i++){
			si1(mnth);
			sd1(inte);
			loa_in[mnth] = inte;
		}
		for(int i=1; i<month; i++){
			if(loa_in[i] == -1){
				loa_in[i] = loa_in[i-1];
			}
		}
		_val = loan_amnt+pay;
		_val = _val - (_val * loa_in[0]);
		pay = loan_amnt / month;
		ans = 0;
		for(int i=1; _val<loan_amnt; i++,ans++){
			_val = _val - (_val * loa_in[i]);
			loan_amnt-=pay;
		}
		pf("%d ",ans);
		pf(ans==1 ? "month\n" : "months\n");
	}
	return 0;
}
