#include <stdio.h>
int main(int argc,char *arv[])
{
        int n,f,area,animals,env;
	long long int budget;
        scanf("%d",&n);
        while(n>0)
	{
		budget=0;
		scanf("%d",&f);
		while(f>0)
		{
                        scanf("%d%d%d",&area,&animals,&env);
			budget = budget + (area*env);
			f--;
		}
		printf("%lld\n",budget);
		n--;
        }
	return 0;
}
