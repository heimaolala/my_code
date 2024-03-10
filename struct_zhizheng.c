#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    char* name;
    int age;
    int* score;
    char* addr;
};
int main()
{
    struct student stu;
    stu.name=malloc(sizeof(char)*21);
    stu.score=malloc(sizeof(int)*3);
    stu.addr=malloc(sizeof(char)*56);
    strcpy(stu.name,"张三");
    stu.age=18;
    stu.score[0]=60;
    stu.score[1]=61;
    stu.score[2]=62;
    strcpy(stu.addr,"北京昌平");
    printf("%s\n%d\n%d\n%d\n%d\n%s\n",stu.name,stu.age,stu.score[0],stu.score[1],stu.score[2],stu.addr);
    free(stu.name);
    free(stu.score);
    free(stu.addr);
    return 0;
}