/* UVa 11559 - Event Planning */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
        int N,B,H,W,p,b,ans,calc;
        bool fl;
        while(cin >> N >> B >> H >> W)
        {
		ans=0x7fffffff;
		fl=false;
		for(int i=0;i<H;i++)
		{
			cin >> p;
			for(int j=0;j<W;j++)
			{
				calc=0;
				cin >> b;
				if(b>=N)
				{
					calc=N*p;
				}
				if(calc<=B && calc<ans && calc!=0)
				{
					ans=calc;
					fl=true;
				}
			}
		}
		if(fl)
		{
			cout << ans << "\n";
		}else cout << "stay home\n";
        }
        return 0;
}
