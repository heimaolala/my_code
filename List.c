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
    return 0;
}