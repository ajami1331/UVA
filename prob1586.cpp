/* UVa 1586 - Molar mass */
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	int tc,c,h,o,n;
	double ans;
	string s;
	while(cin>>tc)
	{
		while(tc--)
		{
			cin>>s;
			ans=0;c=0;h=0;o=0;n=0;
                        for(int i=0;i<s.size();i++)
                        {
				if(s[i]=='C')
				{
					c++;
				}else if(s[i]=='H')
				{
					h++;
				}else if(s[i]=='O')
				{
					o++;
				}else if(s[i]=='N')
				{
					n++;
				}
				else if(s[i]>='0' && s[i]<='9')
				{
					if(s[i-1]=='C')
					{
						c+=(s[i]-'0'-1);
					}else if(s[i-1]=='H')
					{
						h+=(s[i]-'0'-1);
					}else if(s[i-1]=='O')
					{
						o+=(s[i]-'0'-1);
					}else if(s[i-1]=='N')
					{
						n+=(s[i]-'0'-1);
					}else if(s[i-1]>='0' && s[i-1]<='9')
					{
						if(s[i-2]=='C')
						{
							c+=((s[i-1]-'0')*10)+(s[i]-'0'-(s[i-1]-'0'));
						}else if(s[i-2]=='H')
						{
							h+=((s[i-1]-'0')*10)+(s[i]-'0'-(s[i-1]-'0'));
						}else if(s[i-2]=='O')
						{
							o+=((s[i-1]-'0')*10)+(s[i]-'0'-(s[i-1]-'0'));
						}else if(s[i-2]=='N')
						{
							n+=((s[i-1]-'0')*10)+(s[i]-'0'-(s[i-1]-'0'));
						}
					}
				}
                        }
			ans=(c*12.01)+(h*1.008)+(o*16.00)+(n*14.01);
			printf("%.3lf\n",ans);
		}
	}
	return 0;
}
