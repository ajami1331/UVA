/* 369 - Combinations */
#include <iostream>
#include <cstdio>

using namespace std;

long long int nCr(int n,int m)
{
        if(n==m)
        {
		return 1;
        }else if(m==1)
        {
		return n;
        }else
        {
		long long int ans=1;
		if(n-m<m)
		{
			m=n-m;
		}
		for(int i=1;i<=m;i++,n--)
		{
			ans=ans*n/i;
		}
		return ans;
        }
        return 1;
}

int main()
{
	#ifdef ONLINE_JUDGE
		ios_base :: sync_with_stdio(0);
		cin.tie(0);
	#endif // ONLINE_JUDGE
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	int m,n,n_m;
	long long int c;
	while(cin >> n >> m)
	{
		if(n==0 && m==0)
		{
			 break;
		}
		c=nCr(n,m);
		cout <<  n << " things taken " << m << " at a time is " << c << " exactly." << endl;
	}
	return 0;
}
