#include <stdio.h>
int main(int argc,char *argv[])
{
        int t,a,b;
        scanf("%d",&t);
        while(t>0)
        {
                scanf("%d%d",&a,&b);
                if(a==b)
                {
			printf("=\n");
		}else if(a<b)
		{
			printf("<\n");
		}else if(a>b)
		{
			printf(">\n");
		}
		t--;
        }
	return 0;
}
