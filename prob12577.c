/* UVa 12577 Hajj-e-Akbar */
#include <stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
        char str[5];
        int cnt=0;
        while(scanf("%s",str)==1)
        {
		cnt++;
		if(str[0]=='*') break;
                if(str[0]=='H') printf("Case %d: Hajj-e-Akbar\n",cnt);
                else if(str[0]=='U') printf("Case %d: Hajj-e-Asghar\n",cnt);
        }
	return 0;
}
