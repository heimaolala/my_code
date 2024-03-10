#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("D:/c/c/file_study/row_read.txt","r");
    if(!fp)
    {
        printf("文件初始化失败");
        return -1;
    }
    char* p=malloc(sizeof(char)*100);
    //指定读取第1+ 1 行；
    for(int i=0;i<1;i++)
    {
        fgets(p,100,fp);
    }
    while(!feof(fp))
    {
        memset(p,0,100);
        fgets(p,100,fp);
        printf("%s",p);
    }
    printf("\n");
    free(p);
    fclose(fp);
    return 0;
}