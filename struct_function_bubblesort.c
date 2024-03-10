#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student ss;
struct student
{
    char name[21];
    int age;
};
void BubbleSort(ss stu[3],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(stu[j].age>stu[j+1].age)
            {
                ss temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
}
int main()
{
    ss stu[3]=
    {
        {"张三",18},
        {"李四",25},
        {"王五",21}
    };
    BubbleSort(stu,3);
    for(int i=0;i<3;i++)
    {
        printf("姓名：%s\n年龄：%d\n",stu[i].name,stu[i].age);
    }
    return 0;
}