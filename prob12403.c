/* UVa 12403 Save Setu */
#include <stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif /* ONLINE_JUDGE */
	int t,a,ans;
        char str[7];
        while(scanf("%d",&t)==1)
        {
		ans=0;
                while(t--)
                {
                        scanf("%s",str);
                        if(str[0]=='d')
                        {
				scanf("%d",&a);
				ans+=a;
                        }else if(str[0]=='r')
                        {
                                printf("%d\n",ans);
                        }
                }
        }
        return 0;
}
