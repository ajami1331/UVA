#include <stdio.h>
int main(int argc,char *argv[])
{
	int i,j;
	while(scanf("%d%d",&i,&j)==2)
	{
		int lenth,max_lenth,itemp,jtemp;
		itemp = i;
		jtemp = j;
		lenth = 0;
		max_lenth = 0;
		if(i>j)
		{
			i=jtemp;
			j=itemp;
		}
		while(i<=j)
		{
			unsigned int n = i;
			lenth = 1;
			while(n!=1)
			{
				if(n & 1)
				{
					n = (3*n)+1;
				}else n = n/2;
				lenth++;
			}
			if(lenth>max_lenth)
			{
				max_lenth = lenth;
			}
			i++;
		}
		printf("%d %d %d\n",itemp,jtemp,max_lenth);
	}
	return 0;
}

