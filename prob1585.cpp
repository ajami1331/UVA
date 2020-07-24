/* UVa 1585 - Score */
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int tc,ans,kn;
        string s;
        while(cin >> tc)
        {
		while(tc--)
		{
			kn=0;
			ans=0;
			cin >> s;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='X')
				{
					kn=0;
				}else kn++;
				ans+=kn;
			}
			cout << ans << endl;
		}
        }
	return 0;
}
