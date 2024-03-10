#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp1=fopen("D:/c/c/file_study/QQpassword.txt","r");
    FILE* fp2=fopen("D:/c/c/file_study/S_QQpassword.txt","w");
    if(!fp1||!fp2)
    {
        printf("初始化文件失败");
        return -1;
    }
    char ch;
    while((ch=fgetc(fp1))!=EOF)
    {
        ch++;
        fputc(ch,fp2);
    }
    printf("加密成功!");
    fclose(fp1);
    fclose(fp2);
    return 0;
}