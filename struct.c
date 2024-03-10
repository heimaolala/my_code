#include <stdio.h>
#include <string.h>
struct student
{
    char name[21];
    int age;
    int score;
    char addr[56];
};
int main()
{
    struct student stu;
        strcpy(stu.name,"李程");
        stu.age=18;
        stu.score=100;
        strcpy(stu.addr,"沙河校区");
    

    /*     struct studnt stu ={"李程",18,100,"沙河"}; */
/* 
    scanf("%s%d%d%s", stu.name, &stu.age, &stu.score, stu.addr); */

    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%d\n", stu.score);
    printf("%s\n", stu.addr);
    return 0;
}