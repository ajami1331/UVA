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

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	char c;
	while(sf("%c",&c) != EOF){
		switch(c){
			case '1':
				putchar('`');
				break;
			case '2':
				putchar('1');
				break;
			case '3':
				putchar('2');
				break;
			case '4':
				putchar('3');
				break;
			case '5':
				putchar('4');
				break;
			case '6':
				putchar('5');
				break;
			case '7':
				putchar('6');
				break;
			case '8':
				putchar('7');
				break;
			case '9':
				putchar('8');
				break;
			case '0':
				putchar('9');
				break;
			case '-':
				putchar('0');
				break;
			case '=':
				putchar('-');
				break;
			case 'W':
				putchar('Q');
				break;
			case 'E':
				putchar('W');
				break;
			case 'R':
				putchar('E');
				break;
			case 'T':
				putchar('R');
				break;
			case 'Y':
				putchar('T');
				break;
			case 'U':
				putchar('Y');
				break;
			case 'I':
				putchar('U');
				break;
			case 'O':
				putchar('I');
				break;
			case 'P':
				putchar('O');
				break;
			case '[':
				putchar('P');
				break;
			case ']':
				putchar('[');
				break;
			case '\\':
				putchar(']');
				break;
			case 'S':
				putchar('A');
				break;
			case 'D':
				putchar('S');
				break;
			case 'F':
				putchar('D');
				break;
			case 'G':
				putchar('F');
				break;
			case 'H':
				putchar('G');
				break;
			case 'J':
				putchar('H');
				break;
			case 'K':
				putchar('J');
				break;
			case 'L':
				putchar('K');
				break;
			case ';':
				putchar('L');
				break;
			case '\'':
				putchar(';');
				break;
			case 'X':
				putchar('Z');
				break;
			case 'C':
				putchar('X');
				break;
			case 'V':
				putchar('C');
				break;
			case 'B':
				putchar('V');
				break;
			case 'N':
				putchar('B');
				break;
			case 'M':
				putchar('N');
				break;
			case ',':
				putchar('M');
				break;
			case '.':
				putchar(',');
				break;
			case '/':
				putchar('.');
				break;
			default:
				putchar(c);
				break;
		}
	}
	return 0;
}

