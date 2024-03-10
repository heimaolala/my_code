#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student ss;//自定义结构体类型名称
struct student//创建结构体
{
    char* name;
    int age;
    int* score;
    char* addr;
};
int main()
{
    ss* p=malloc(sizeof(ss)*3);//为结构体开辟三段内存，返回地址到P
    for(int i=0;i<3;i++)//for循环，分别为结构体成员指针开辟内存，方便其储存空间，返回内存首地址到各结构体成员指针；
    {
        p[i].name=malloc(sizeof(char)*21);
        p[i].score=malloc(sizeof(int)*3);
        p[i].addr=malloc(sizeof(char)*56);
    }
    for(int i=0;i<3;i++)//输入数据
    {
        scanf("%s%d%d%d%d%s",p[i].name,&p[i].age,&p[i].score[0],&p[i].score[1],&p[i].score[2],(p+i)->addr);
    }
    for(int i=0;i<3;i++)//打印结果
    {
        printf("姓名：%s\n年龄：%d\n语文：%d\n数学：%d\n英语：%d\n地区：%s\n",p[i].name,p[i].age,p[i].score[0],(p+i)->score[1],(p+i)->score[2],(p+i)->addr);
        printf("\n");
    }
    for(int i=0;i<3;i++)//释放结构体成员堆空间
    {
        free(p[i].name);
        free(p[i].score);
        free((p+i)->addr);
    }
    free(p);//释放结构体堆空间
    return 0;
}