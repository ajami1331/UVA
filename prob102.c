#include <stdio.h>
int main(int argc,char *argv[])
{
    int i,b1,b2,b3,g1,g2,g3,c1,c2,c3;
    long long min,s[6];
    while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {
        min=c1+c2+c3+b1+b2+b3+g1+g2+g3;
        s[0]=c1+c3+b2+b3+g1+g2; /*BCG*/
        s[1]=c1+c2+b2+b3+g1+g3; /*BGC*/
        s[2]=c2+c3+b1+b3+g1+g2; /*CBG*/
        s[3]=c2+c3+b1+b2+g1+g3; /*CGB*/
        s[4]=c1+c2+b1+b3+g2+g3; /*GBC*/
        s[5]=c1+c3+b1+b2+g2+g3; /*GCB*/
        s[6]=0;
        for(i=0;i<6;i++)
        {
            if(s[i]<min)
            {
                min = s[i];
            }
        }
            if(min==s[0])
                printf("BCG %lld\n",min);
            else if(min==s[1])
                printf("BGC %lld\n",min);
            else if(min==s[2])
                printf("CBG %lld\n",min);
            else if(min==s[3])
                printf("CGB %lld\n",min);
            else if(min==s[4])
                printf("GBC %lld\n",min);
            else if(min==s[5])
                printf("GCB %lld\n",min);
    }
    return 0;
}
