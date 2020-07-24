#include <stdio.h>
#include <math.h>
int main()
{
        int t,n;
        while(scanf("%d",&t)==1)
        {
		while(t--)
		{
                        scanf("%d",&n);
                        n*=567;
                        n/=9;
                        n+=7492;
                        n*=235;
                        n/=47;
                        n-=498;
                        n/=10;
                        n=abs(n%10);
                        printf("%d\n",n);
		}
        }
	return 0;
}
