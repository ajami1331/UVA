/* UVa 12015 - Google is Feeling Lucky */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int tc,csn,n[10],m;
	string h;
	vector <string> vs;
	while(cin >> tc)
	{
		csn=0;
		while(tc--)
		{
			vs.clear();
			m=-100;
			for(int i=0;i<10;i++)
			{
				cin >> h >> n[i];
				vs.push_back(h);
				if(m<n[i])
				{
					m=n[i];
				}
			}
			cout << "Case #" << ++csn << ":\n";
			for(int i=0;i<10;i++)
			{
				if(n[i]==m)
				{
					cout << vs[i] << "\n";
				}
			}
		}
	}
	return 0;
}
