#include <stdio.h>
int main()
{
	int K,N,M,X,Y;
	while(scanf("%d",&K)==1 && K!=0)
	{
                scanf("%d%d",&N,&M);
                while(K--)
                {
                        scanf("%d%d",&X,&Y);
                        if(X==N || Y==M)
                        {
                                printf("divisa\n");
                        }else if((X-N)>0 && (Y-M)>0)
                        {
                                printf("NE\n");
                        }else if((X-N)>0 && (Y-M)<0)
                        {
				printf("SE\n");
                        }else if((X-N)<0 && (Y-M)<0)
                        {
				printf("SO\n");
                        }else if((X-N)<0 && (Y-M)>0)
                        {
				printf("NO\n");
                        }
                }
	}
	return 0;
}
