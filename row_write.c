#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("D:/c/c/file_study/row_write.txt","w");
    if(!fp)
    {
        printf("初始化文件失败");
        return -1;
    }
    char* ch=malloc(sizeof(char)*1024);
    while(1)
    {
        fgets(ch,1024,stdin);
        if(*ch=='@')
        {
            break;
        }
        fputs(ch,fp);
    }
    free(ch);
    fclose(fp);
    return 0;
}