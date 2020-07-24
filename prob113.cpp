// UVa 113 Power of Cryptography
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	double n,p,ans;
	while(cin>>n)
	{
		cin>>p;
		n=1/n;
		ans=pow(p,n);
                cout<<fixed<<setprecision(0)<<ans<<endl;
	}
	return 0;
}
