#include<stdio.h>
#include<string.h>
struct scores
{
    int c;
    int cpp;
    int cfp;
};
struct student
{
    char name[21];
    int age;
    struct scores code;
    char addr[56];
};

int main()
{
    struct student stu;
    strcpy(stu.name,"张三");
    stu.age=18;
    stu.code.c=60;
    stu.code.cpp=60;
    stu.code.cfp=60;
    strcpy(stu.addr,"北京昌平");
    printf("%s\n%d\n%d\n%d\n%d\n%s\n",stu.name,stu.age,stu.code.c,stu.code.cpp,stu.code.cfp,stu.addr);
    return 0;
}