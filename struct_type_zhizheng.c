#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student ss;
struct student
{
    char name[21];
    int age;
    int score[3];
    char addr[56];
};
int main()
{
    ss stu={"张三",18,71,72,73,"北京昌平"};
    ss* p=&stu;
    /* printf("%s\n",(*p).name);
    printf("%d\n",(*p).age);
    printf("%d\n",(*p).score[0]);
    printf("%d\n",(*p).score[1]);
    printf("%d\n",(*p).score[2]);
    printf("%s\n",(*p).addr); */
    printf("%s\n",p->name);
    printf("%d\n",p->age);
    printf("%d\n",p->score[0]);
    printf("%d\n",p->score[1]);
    printf("%d\n",p->score[2]);
    printf("%s\n",p->addr);
    return 0;
}