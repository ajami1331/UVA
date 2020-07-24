#include <stdio.h>

int main()
{
    long long a,b;
    long long ans;

    while(scanf("%lld%lld",&a,&b)==2){
        ans =a-b;
        if(ans<0)ans=ans*-1;
        printf("%lld\n",ans);
    }
    return 0;
}
