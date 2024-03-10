#include<stdio.h>
#include<string.h>
int main()
{
    /* 这个是去空格 */
/*     char a[100];
    gets(a);
    char b[100];
    int i=0,k=0;
    for(;a[i]!=0;i++)
    {
        if(a[i]!=' ')
        {
            b[k]=a[i];
            k++;
        }
    }
    printf("%s\n",b); */
    
    /* 这个是统计字母出现次数 */
    char abc[100];
    scanf("%s",abc);
    int abc_count[26]={0};
    int i=0;
    for (;abc[i]!=0;i++)
    {
        abc_count[abc[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(abc_count[i]!=0)
        {
            printf("字母%c,出现了%d次\n",'a'+i,abc_count[i]);
        }
    }
    return 0;
}