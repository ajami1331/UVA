#include <stdio.h>
int main()
{
        int n,k=1,ans,l;
        while(scanf("%d",&n)==1 && n!=0)
        {
		ans=0;
		while(n--)
		{
			scanf("%d",&l);
			if(l==0)
			{
				ans--;
			}else ans++;
		}
		printf("Case %d: %d\n",k,ans);
		k++;
        }
	return 0;
}
