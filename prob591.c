#include <stdio.h>
#include <stdlib.h>
int main(int arg,char *argv[])
{
	int n,h[50],count=0,minmove,j,sum,avg;
        while(scanf("%d",&n)==1)
        {
		minmove=0;
		sum=0;
		if(n==0)
		{
			return 0;
		}
		j=n;
		while(j>0)
		{
                        scanf("%d",&h[j]);
                        sum=sum+h[j];
                        j--;
		}
		avg=sum/n;
		j=n;
		while(j>0)
		{
                        if(h[j]>avg)
                        {
				minmove=minmove+(abs(h[j]-avg));
                        }
                        j--;
		}
		count++;
		printf("Set #%d\n",count);
		printf("The minimum number of moves is %d.\n\n",minmove);
        }
	return 0;
}
