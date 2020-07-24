#include <stdio.h>
#include <string.h>
int main()
{
	int k=1;
	char str[15];
	while(gets(str))
	{
		if(str[0]=='#')
		{
			break;
		}else
		if(strcmp(str,"HELLO")==0)
                {
			printf("Case %d: ENGLISH\n",k);
                }else
		if(strcmp(str,"HALLO")==0)
                {
			printf("Case %d: GERMAN\n",k);
                }else
		if(strcmp(str,"HOLA")==0)
                {
			printf("Case %d: SPANISH\n",k);
                }else
		if(strcmp(str,"BONJOUR")==0)
                {
			printf("Case %d: FRENCH\n",k);
                }else
		if(strcmp(str,"CIAO")==0)
                {
			printf("Case %d: ITALIAN\n",k);
                }else
		if(strcmp(str,"ZDRAVSTVUJTE")==0)
                {
			printf("Case %d: RUSSIAN\n",k);
                }else
                {
			printf("Case %d: UNKNOWN\n",k);
                }
                k++;
	}
	return 0;
}
