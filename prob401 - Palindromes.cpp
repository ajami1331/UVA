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

map <char,char> mirror, own;

int mCount;

bool isPal;

bool isMirror(char c,char f){
	return mirror[c] == f || mirror[f] == c;
}

void isPalinrdrome(string s){
	bool mir;
	isPal = true;
	if(own[s[s.size()>>1]] && s.size()&1){
		mCount = 1;
	}else{
		mCount = 0;
	}
	for(int i=0,j=s.size()-1; i<j; i++,j--){
		mir = false;
		if(isMirror(s[i],s[j])){
			mir = true;
			mCount += 2;
		}
		if(s[i] != s[j]){
			isPal = false;
		}
	}
}

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
		//freopen("i.txt","w+",stdout);
	#endif // LU_SERIOUS
	mirror['A'] = 'A';
	mirror['E'] = '3';
	mirror['H'] = 'H';
	mirror['I'] = 'I';
	mirror['L'] = 'J';
	mirror['J'] = 'L';
	mirror['M'] = 'M';
	mirror['O'] = 'O';
	mirror['S'] = '2';
	mirror['T'] = 'T';
	mirror['U'] = 'U';
	mirror['V'] = 'V';
	mirror['W'] = 'W';
	mirror['X'] = 'X';
	mirror['Y'] = 'Y';
	mirror['Z'] = '5';
	mirror['1'] = '1';
	mirror['2'] = 'S';
	mirror['5'] = 'Z';
	mirror['8'] = '8';

	own['A'] = 'A';
	own['H'] = 'H';
	own['I'] = 'I';
	own['M'] = 'M';
	own['O'] = 'O';
	own['T'] = 'T';
	own['U'] = 'U';
	own['V'] = 'V';
	own['W'] = 'W';
	own['X'] = 'X';
	own['Y'] = 'Y';
	own['1'] = '1';
	own['8'] = '8';
	string s;
	while(cin >> s){
		isPalinrdrome(s);
		if(isPal){
			if(mCount == s.size()){
				cout << s << " -- is a mirrored palindrome.";
			}else{
				cout << s << " -- is a regular palindrome.";
			}
		}else if(mCount == s.size()){
			cout << s << " -- is a mirrored string.";
		}else{
			cout << s << " -- is not a palindrome.";
		}
		cout << "\n\n";
	}
	return 0;
}

