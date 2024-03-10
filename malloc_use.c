#include<stdio.h>
#include<stdlib.h>
int main()
{
    int** p=malloc(sizeof(int*)*5);
    for(int n=0;n<5;n++)
    {
        p[n]=malloc(sizeof(int)*3);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
    for(int n=0;n<5;n++)
    {
        free(p[n]);
    }
    free(p);
    return 0;
}