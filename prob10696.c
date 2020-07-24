/*UVA 10696 f91*/
#include <stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	int n;
        while(scanf("%d",&n)==1 && n!=0)
        {
                n>=101 ? printf("f91(%d) = %d\n",n,n-10) : printf("f91(%d) = 91\n",n);
        }
	return 0;
}
