#include <stdio.h>
int main(int argc,char *argv[])
{
        int a,b,c,n,ans,temp;
        while(scanf("%d %d %d %d",&n,&a,&b,&c)==4)
        {
		if(a==b && b==c && c==n && n==0)
		{
			break;
		}
		ans=1080;
		temp=n-a;
		if(temp<0)
		{
			temp+=40;
		}
		ans=ans+(temp*9);
		temp=b-a;
		if(temp<0)
		{
			temp+=40;
		}
		ans=ans+(temp*9);
		temp=b-c;
		if(temp<0)
		{
			temp+=40;
		}
		ans=ans+(temp*9);

		printf("%d\n",ans);
        }
	return 0;
}
