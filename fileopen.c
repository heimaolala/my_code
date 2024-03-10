#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("D:/c/c/file_study/fileopen.txt","r");
    if(fp==NULL)
    {
        printf("文件打开失败。");
        return -1;
    }
    printf("文件打开成功：%p",fp);
    fclose(fp);
    return 0;
}