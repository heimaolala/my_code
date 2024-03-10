#include<stdio.h>
#include<string.h>

/* 以下是输出倒置 */

/* void exc(char* abc)
{
    char temp;
    int i=0;
    int j=strlen(abc)-1;
    while(i<j)
    {
        temp=abc[i];
        abc[i]=abc[j];
        abc[j]=temp;
        i++;
        j--;
    }
    return;
}
int main()
{
    char abc[100];
    scanf("%s",abc);
    exc(abc);
    printf("%s\n",abc);
    return 0;
} */

/* 以下是检测回文数 */
int exc(char* abc)
{
    char temp;
    int i=0;
    int j=strlen(abc)-1;
    while(i<j)
    {
        if(abc[i]!=abc[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char abc[100];
    gets(abc);
    int value;
    value=exc(abc);
    if(value==0)
    {
        printf("不是");
    }
    else
    {
        printf("是");
    }
    return 0;
}