#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE * fp=fopen("D:/c/c/file_study/fileopen2.txt","r");
    if(!fp)
    {
        printf("文件读取失败\n");
        return -1;
    }
    char ch;
    int a=0;
    printf("文件内容：\n");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
        if(ch=='\n')
        {
            a++;
        }
    }
    printf("\n");
    printf("%d\n",a+1);
    fclose(fp);
    return 0;
}