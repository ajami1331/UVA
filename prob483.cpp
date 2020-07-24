/* UVa 483 - Word Scramble */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	string line,tok;
	vector<char> vc;
	bool flag;
	while(getline(cin,line))
	{
		flag=false;
		istringstream ss(line);
		while(ss >> tok)
		{
			vc.clear();
			if(flag==false)
			{
				flag=true;
			}else cout << " ";
			for(int i=0;i<tok.size();i++)
			{
				vc.push_back(tok[i]);
			}
			reverse(vc.begin(),vc.end());
			for(int i=0;i<vc.size();i++)
			{
				cout<<vc[i];
			}
		}
		cout << endl;
	}
	return 0;
}
