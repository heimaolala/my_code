#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp1=fopen("D:/c/c/file_study/for_culculate.txt","r");
    FILE* fp2=fopen("D:/c/c/file_study/for_culculate_answer.txt","w");
    int a,b,sum;
    char c;
    char* p=malloc(sizeof(char)*10);
    for(int i=0;i<100;i++)
    {
        memset(p,0,10);
        fgets(p,10,fp1);
        sscanf(p,"%d%c%d=\n",&a,&c,&b);
        switch (c)
        {
        case '+':sum=a+b;break;
        case '-':sum=a-b;break;
        case '*':sum=a*b;break;
        case '/':sum=a/b;break;
        }
        memset(p,0,10);
        sprintf(p,"%d%c%d=%d\n",a,c,b,sum);
        fputs(p,fp2);
    }
    printf("答案已生成!");
    free(p);
    fclose(fp1);
    fclose(fp2);
    return 0;
}