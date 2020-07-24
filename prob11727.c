#include <stdio.h>
int main()
{
	int t,k,a,b,c;
	while(scanf("%d",&t)==1)
	{
		k=1;
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
                        if((a>c&&a<b)||(c>a&&a>b))
                        {
				printf("Case %d: %d\n",k,a);
                        }else if((b>a&&b<c)||(a>b&&b>c))
                        {
				printf("Case %d: %d\n",k,b);
                        }else if((a>c&&c>b)||(c>a&&c<b))
                        {
				printf("Case %d: %d\n",k,c);
                        }
                        k++;
		}
	}
	return 0;
}
