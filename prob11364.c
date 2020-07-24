#include <stdio.h>
int main()
{
        int t,a,b,ans,low,high;
        while(scanf("%d",&t)==1)
        {
                while(t--)
                {
			low=100;
			high=0;
			scanf("%d",&a);
			while(a--)
			{
				scanf("%d",&b);
				if(b>high)
				{
					high=b;
				}if(b<low)
				{
					low=b;
				}
			}
			ans=2*(high-low);
			printf("%d\n",ans);
                }
        }
	return 0;
}
