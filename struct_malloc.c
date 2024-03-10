#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[21];
    char sex;
    int score[3];
    char addr[56];
};
int main()
{
    struct student* p=malloc(sizeof(struct student)*3);
    for(int i=0;i<3;i++)
    {
        scanf("%s%s%d%d%d%s",p[i].name,&p[i].sex,&p[i].score[0],&p[i].score[1],&p[i].score[2],p[i].addr);
    }
    for(int i=0;i<3;i++)
    {
        printf("姓名：%s\n",p[i].name);
        printf("性别：%s\n",p[i].sex=='M'?"男":"女");
        printf("成绩1：%d\n",p[i].score[0]);
        printf("成绩2：%d\n",p[i].score[1]);
        printf("成绩3：%d\n",p[i].score[2]);
        printf("地址：%s\n",p[i].addr);
        printf("\n");
    }
    free(p);
    return 0;
}