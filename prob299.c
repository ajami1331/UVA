/*UVA 299 Train Swapping solve by CLown1331*/
#include <stdio.h>
#define swp(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
int main()
{
	int t,n,l[50],i,j,cnt;
        while(scanf("%d",&t)==1)
        {
		while(t--)
		{
                        scanf("%d",&n);
			cnt=0;
                       for(i=0;i<n;i++)
                       {
                                scanf("%d",&l[i]);
                       }
                       for(i=0;i<n-1;i++)
                       {
				for(j=0;j<n-i-1;j++)
				{
                                        if(l[j]>l[j+1])
                                        {
						swp(l[j],l[j+1]);
						cnt++;
                                        }
				}
                       }
                       printf("Optimal train swapping takes %d swaps.\n",cnt);
		}
        }
	return 0;
}
