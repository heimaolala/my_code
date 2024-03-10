#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *createList()
{
    struct node* head =malloc(sizeof(struct node));
    head->next=NULL;
    return head;
}
struct node* createNode(int data)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
int main()
{
    struct node* head=createList();
    struct node* tail=head;
    int n=1;
    while(n)//尾插法
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        struct node* newNode =createNode(n);
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }
    struct node* p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    //删除
    struct node* passf=head;
    struct node* pass=head->next;
    printf("\n输入删除的数字:");
    int del;
    scanf("%d",&del);
    if(pass==NULL)
    {
        printf("空链表");
    }
    else
    {
        while(pass->data!=del)
        {
            passf=pass;
            pass=passf->next;
            if(pass==NULL)
            {
                printf("没有该数据");
                goto A;
            }
        }
        passf->next=pass->next;
        pass=passf->next;
        free(pass);
    }
    A://打印
    p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",passf->data);
    printf("%d ",pass->data);
    return 0;
}