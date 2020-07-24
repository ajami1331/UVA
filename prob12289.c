#include <stdio.h>
#include <string.h>
int main()
{
        int t,k=0;
        char str[6];
        while(scanf("%d",&t)==1)
        {
                while(t--)
                {
			scanf("%s",str);
			if(strlen(str)==5)
			{
				printf("3\n");
			}else
			{
				k=0;
				if(str[0]=='t')
				{
					k++;
				}
				if(str[1]=='w')
				{
					k++;
				}
				if(str[2]=='o')
				{
					k++;
				}
				if(k>=2)
				{
					printf("2\n");
				}else printf("1\n");
			}
                }
        }
	return 0;
}
