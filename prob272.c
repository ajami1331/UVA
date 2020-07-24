#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int i,l,p=0;
	char str[100000];
	while(gets(str))
	{
		l=strlen(str);
		for(i=0;i<l;i++)
		{
		    if(str[i]=='"')
		    {
			p++;
			if((p%2)==1)
			{
			    printf("``");
			}else printf("''");
		    }else printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
