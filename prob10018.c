#include <stdio.h>
int main(int argc,char *argv[])
{
	long long int rev,num,ans,j;
	int n;
        scanf("%d",&n);
		while(n>0)
		{
			j=0;
			scanf("%lld",&num);
			ans=num;
			while(1)
			{
                                rev=0;
				while(num!=0)
				{
					rev = (rev * 10) + (num%10);
					num = num/10;
				}
				if(ans==rev)
				{
					break;
				}else
				{
                                        num=ans+rev;
                                        ans=ans+rev;
					j++;
				}
			}
			printf("%lld %lld\n",j,ans);
			n--;
		}
	return 0;
}
