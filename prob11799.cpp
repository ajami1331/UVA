/* UVa 11799 - Horror Dash */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int tc,n,h,m,csn;
	while(cin >> tc)
	{
		csn=0;
		while(tc--)
		{
			m=-1000;
			cin >> n;
			for(int i=0;i<n;i++)
			{
				cin >> h;
				if(h>m) m=h;
			}
			cout << "Case " << ++csn << ": " << m << "\n";
		}
	}
	return 0;
}
