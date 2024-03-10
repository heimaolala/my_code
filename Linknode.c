#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LinkNode Link;//重命名结构体类型
struct LinkNode//创建节点
{
    int data;
    struct LinkNode* next;
};
void text()
{
    Link node1={10,NULL};//定义节点数据域和指针域
    Link node2={20,NULL};
    Link node3={30,NULL};
    Link node4={40,NULL};
    Link node5={50,NULL};
    Link node6={60,NULL};

    node1.next=&node2;//将节点之间用指针链接
    node2.next=&node3;
    node3.next=&node4;
    node4.next=&node5;
    node5.next=&node6;

    Link* pCurrent=&node1;//定义遍历类型pCurrent，使其自动移动至下一节点
    while(pCurrent!=NULL)
    {
        printf("%d\n",pCurrent->data);
        pCurrent=pCurrent->next;
    }
}
int main()
{
    text();
    return 0;
}