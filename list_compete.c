#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* Creatlist()
{
    node* head=malloc(sizeof(node));
    node* tail=head;
    head->next=NULL;
    int i=0;
    while(i<6)
    {
        node* node=malloc(sizeof(node));
        node->data=0;
        node->next=NULL;
        tail->next=node;
        tail=node;
        i++;
    }
    return head;
}
int main()
{
    node* head=Creatlist();
    node* p=head->next;
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    printf("%d\n",i);
    return 0;
}