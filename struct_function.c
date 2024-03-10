#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student ss;
struct student
{
    char* name;
};
void fun01(ss stu1)
{
    stu1.name=malloc(sizeof(char)*21);
    strcpy(stu1.name,"李四");
    printf("%s\n",stu1.name);
}
int main()
{
    ss stu;
    stu.name=malloc(sizeof(char)*21);
    strcpy(stu.name,"张三");
    fun01(stu);
    printf("%s\n",stu.name);
    free(stu.name);
    return 0;
}