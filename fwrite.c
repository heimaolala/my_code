#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE* fp=fopen("D:/c/c/file_study/fwrite.txt","r");
    /* char a[5]={'x','x','x','x','x'};
    int b[5]={1,2,3,4,5};
    fwrite(a,sizeof(char),5,fp);
    fwrite(b,sizeof(int),5,fp); */
    char aa[5];
    int bb[5];
    fread(aa,sizeof(char),5,fp);
    fread(bb,sizeof(int),5,fp);
    printf("%s",aa);
    for(int i=0;i<4;i++)
        printf("%d",bb[i]);
    fclose(fp);
    return 0;
}