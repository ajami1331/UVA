/* UVa 11764 - Jumping Mario */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
        int tc,n,h,f,hc,lc,csn;
        while(cin >> tc)
        {
		csn=0;
		while(tc--)
		{
			cin >> n;
			cin >> f;
			hc=lc=0;
			for(int i=0;i<n-1;i++)
			{
				cin >> h;
				if(f>h) lc++;
				if(f<h) hc++;
				f=h;
			}
			cout << "Case " << ++csn << ": " << hc << " " << lc << "\n";
		}
        }
	return 0;
}
