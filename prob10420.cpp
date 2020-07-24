/* UVa 10420 - List of Conquests */
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n;
	string country,dump;
	map<string,int> mappa;
	map<string,int> :: iterator it;
        while(cin >> n)
        {
		while(n--)
		{
			cin >> country;
			getline(cin,dump);
			mappa[country]++;
		}
		for(it=mappa.begin(); it!=mappa.end(); it++)
		{
			cout << it->first << " " << it->second << "\n";
		}
        }
	return 0;
}
