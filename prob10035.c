/* UVA 10035 Primary Arithmetic */
#include <stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt","w", stdout);
	#endif
        int c,ans,a,b;
        while(scanf("%d%d",&a,&b)==2)
        {
		if(a==0&&b==0) break;
		c=0;
		ans=0;
		while((a+b)!=0)			     /*loop will run until sum of digits are zero*/
		{				     /*carry is one if carry+digits of both */
                        c=((a%10)+(b%10)+c)>9 ? 1:0; /*numbers is greater then 9 else carry is zero*/
                        ans+= c!=0 ? 1:0;	     /*ans is incremented whenever carry is not zero*/
                        a/=10;		             /*a is set a/10*/
                        b/=10;			     /*b is set to b/10*/
		}
		if(ans==0)
		{
			printf("No carry operation.\n");
		}else ans>1 ? printf("%d carry operations.\n",ans) : printf("%d carry operation.\n",ans);
        }
        return 0;
}
