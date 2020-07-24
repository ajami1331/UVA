/* UVa 11332 - Summing Digits */
#include <cstdio>
#include <iostream>
using namespace std;
int sod(int n)
{
	int ans=0;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	}
	if(ans>9) ans=sod(ans);
	return ans;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n;
	while(cin >> n && n!=0)
	{
		cout << sod(n) << "\n";
	}
	return 0;
}
