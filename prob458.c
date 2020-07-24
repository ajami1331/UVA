#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
    int i,l;
    char str[100000];
    while(gets(str))
    {
        l = strlen(str);
        for(i=0;i<l;i++)
        {
            str[i]= str[i]-7;
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
