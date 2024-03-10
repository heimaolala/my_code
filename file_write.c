#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("D:/c/c/file_study/file_write.c","w");
    if(!fp)
    {
        printf("文件打开失败");
        return -1;
    }
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='@')
        {
            break;
        }
        fputc(ch,fp);
    }
    fclose(fp);
    return 0;
}