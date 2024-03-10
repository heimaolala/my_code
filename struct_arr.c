#include<stdio.h>
struct student
{
    char name[21];
    char sex;
    int score[3];
    char addr[56];
};

int main()
{
    struct student stu[3]=
    {
        {"张三",'M',59,59,59,"北京昌平"},
        {"李四",'M',20,20,20,"北京朝阳"},
        {"小花",'F',60,60,60,"北京海淀"}
    };
    for(int i=0;i<3;i++)
    {
        printf("姓名：%s\n",stu[i].name);
        printf("性别：%s\n",stu[i].sex=='M'?"男":"女");
        printf("成绩1：%d\n",stu[i].score[0]);
        printf("成绩2：%d\n",stu[i].score[1]);
        printf("成绩3：%d\n",stu[i].score[2]);
        printf("地址：%s\n",stu[i].addr);
        printf("\n");
    }
    printf("排序后：\n");
    for(int i=0;i<3-1;i++)
    {
        for(int j=0;j<3-1-i;j++)
        {
            if(stu[j].score[0]>stu[j+1].score[0])
            {
                struct student temp =stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        printf("姓名：%s\n",stu[i].name);
        printf("性别：%s\n",stu[i].sex=='M'?"男":"女");
        printf("成绩1：%d\n",stu[i].score[0]);
        printf("成绩2：%d\n",stu[i].score[1]);
        printf("成绩3：%d\n",stu[i].score[2]);
        printf("地址：%s\n",stu[i].addr);
        printf("\n");
    }
    return 0;
}