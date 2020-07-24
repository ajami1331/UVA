#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char c[31];
	int lenth,i;
	while(gets(c))
	{
                lenth=strlen(c);
                for(i=0;i<lenth;i++)
                {
			if(c[i]>='A' && c[i]<='C')
			{
				printf("2");
			}else if(c[i]>='D' && c[i]<='F')
			{
				printf("3");
			}else if(c[i]>='G' && c[i]<='I')
			{
				printf("4");
			}else if(c[i]>='J' && c[i]<='L')
			{
				printf("5");
			}else if(c[i]>='M' && c[i]<='O')
			{
				printf("6");
			}else if(c[i]>='P' && c[i]<='S')
			{
				printf("7");
			}else if(c[i]>='T' && c[i]<='V')
			{
				printf("8");
			}else if(c[i]>='W' && c[i]<='Z')
			{
				printf("9");
			}else printf("%c",c[i]);
                }
                printf("\n");
	}
	return 0;
}
