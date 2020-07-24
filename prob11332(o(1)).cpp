/* UVa 11332 - Summing Digits */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n,ans;
	while(cin >> n && n!=0)
	{
		if(n%9==0) ans=9;
		else ans=n%9;
		cout << ans << "\n";
	}
	return 0;
}