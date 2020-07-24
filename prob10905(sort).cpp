/* UVa 10905 - Children's Game */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string s1,string s2)
{
	return (s1+s2>s2+s1);
}
int main()
{
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n;
	string h;
	vector<string> vs;
	while(cin >> n && n!=0)
	{
		vs.clear();
		for(int i=0;i<n;i++)
		{
			cin >> h;
			vs.push_back(h);
		}
		sort(vs.begin(), vs.end(), comp);
		for(int i=0;i<n;i++)
		{
			cout << vs[i];
		}
		cout << "\n";
	}
	return 0;
}
