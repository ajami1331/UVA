/* UVa 11942 - Lumberjack Sequencing */
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
        int tc,ar[10];
        bool fl;
        while(cin >> tc)
        {
		cout << "Lumberjacks:\n";
		while(tc--)
		{
			for(int i=0;i<=9;i++)
			{
				cin >> ar[i];
			}
			for(int i=0;i<=8;i++)
			{
				if(ar[i]>ar[i+1])
				{
					fl=true;
				}else
				{
					fl=false;
					break;
				}
			}
			if(!fl)
			{
				for(int i=0;i<=8;i++)
				{
					if(ar[i]<ar[i+1])
					{
						fl=true;
					}else
					{
						fl=false;
						break;
					}
				}
			}
			fl ? cout << "Ordered\n" : cout << "Unordered\n";
		}
        }
	return 0;
}
