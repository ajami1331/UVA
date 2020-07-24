#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int i,l,c,w;
	char str[1000];
	while(gets(str))
	{
		c=0;
		w=1;
                l=strlen(str);
                for(i=0;i<l;i++)
                {
			if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
			{
				if(w==1)
				{
					c++;
					w=0;
				}
			}else w=1;
                }
                printf("%d\n",c);
	}
	return 0;
}
