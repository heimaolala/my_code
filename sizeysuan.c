#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
enum opt
{
    add,sub,mlt,dive
};
int main()
{
    srand((size_t)time(NULL));
    FILE* fp=fopen("D:/c/c/file_study/for_culculate.txt","w");
    if(!fp)
    {
        printf("文件初始化失败");
        return -1;
    }
    int a,b;
    char c;
    char* p=malloc(sizeof(char)*10);
    for(int i=0;i<100;i++)
    {
        a=rand()%10+1;
        b=rand()%10+1;
        switch(rand()%4)
        {
            case add:c='+';break;
            case sub:c='-';break;
            case mlt:c='*';break;
            case dive:c='/';break;
        }
        memset(p,0,10);
        sprintf(p,"%d%c%d=\n",a,c,b);
        fputs(p,fp);
    }
    printf("四则运算表重新生成完毕！");
    free(p);
    fclose(fp);
    return 0;
}