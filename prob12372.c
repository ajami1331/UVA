/* UVa 12372 Packing for Holiday */
#include <stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	int tc,a,b,c,csn;
	while(scanf("%d",&tc)==1)
	{
		csn=0;
                while(tc--)
                {
			scanf("%d%d%d",&a,&b,&c);
                        csn++;
                        if(a>20||b>20||c>20)
                        {
				printf("Case %d: bad\n",csn);
                        }else printf("Case %d: good\n",csn);
                }
	}
	return 0;
}
