/* UVa 499 - What's The Frequency, Kenneth? */
#include <cstdio>
#include <cctype>
#include <cstring>
int main()
{
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif
	char str[1000];
	while(fgets(str, 1000, stdin)!=NULL)
	{
		int ar1[26]={0};
		int ar2[26]={0};
		int s=-1;
                int len=strlen(str);
                for(int i=0;i<len;i++)
                {
			isupper(str[i]) ? ar1[str[i]-'A']++ : ar2[str[i]-'a']++;
                }
                for(int i=0;i<26;i++)
                {
			if(ar1[i]>s)
			{
				s=ar1[i];
			}
			if(ar2[i]>s)
			{
				s=ar2[i];
			}
                }
                for(int i=0;i<26;i++)
                {
			if(ar1[i]==s)
			{
				printf("%c",'A'+i);
			}
                }
                for(int i=0;i<26;i++)
                {
			if(ar2[i]==s)
			{
				printf("%c",'a'+i);
			}
                }
                printf(" %d\n",s);
	}
	return 0;
}
