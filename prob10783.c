#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int t,a,b,l,i,c;
	long long int sum;
	while(scanf("%d",&t)==1)
	{
		sum=0;
		c=0;
                while(t>0)
                {
			scanf("%d",&a);
			scanf("%d",&b);
			l = abs(a-b);
			for(i=0;i<=l;i++)
			{
                                if((a+i)&1==1)
                                {
                                        sum=sum+(a+i);
                                }
			}
			c++;
			printf("Case %d: %lld\n",c,sum);
			sum=0;
			t--;
                }
	}
	return 0;
}
