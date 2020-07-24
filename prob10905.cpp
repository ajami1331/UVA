/* UVa 10905 - Children's Game */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n;
	string h,s1,s2;
	vector<string> vs;
	while(cin >> n && n!=0)
	{
		vs.clear();
		for(int i=0;i<n;i++)
		{
			cin >> h;
			vs.push_back(h);
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				s1=vs[j]+vs[j+1];
				s2=vs[j+1]+vs[j];
				if(s1<s2)
				{
					h=vs[j];
					vs[j]=vs[j+1];
					vs[j+1]=h;
				}
			}
		}
		for(int i=0;i<vs.size();i++)
		{
			cout << vs[i];
		}
		cout << "\n";
	}
	return 0;
}
