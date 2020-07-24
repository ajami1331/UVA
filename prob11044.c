#include <stdio.h>
int main(int argc,char *argv[])
{
        int t,a,b,ans;
        while(scanf("%d",&t)==1)
        {
		while(t>0)
		{
			scanf("%d%d",&a,&b);
			ans=(a/3)*(b/3);
			printf("%d\n",ans);
			t--;
		}
	}
	return 0;
}
