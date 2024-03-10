#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* p=malloc(sizeof(int)*10);
    printf("%p\n",p);
    int i=0;
    for(;i<10;i++)
    {
        p[i]=i;
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",p[i]);
    }
    free(p);
    return 0;
}