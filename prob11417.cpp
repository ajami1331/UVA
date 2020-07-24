/* UVa 11417 - GCD */
#include <iostream>
#include <cstdio>

#define SWAP(a, b)	((a)^=(b),(b)^=(a),(a)^=(b))

using namespace std;

int gcd(int i,int j)
{
	while(j>0)
	{
		i%=j;
		SWAP(i,j);
	}
	return i;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif // ONLINE_JUDGE
        int n=0,g=0;
	while(cin >> n)
	{
		if(n==0) break;
		g=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				g+=gcd(i,j);
			}
		}
		cout << g << endl;
	}
	return 0;
}
