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
    int i=0;
    while(i<6)
    {
        node* node=malloc(sizeof(node));
        node->next=NULL;
        node->data=i;
        tail->next=node;
        tail=node;
        i++;
    }
    return head;
}
int main()
{
    int n=0,new=0;
    node* head=Creatlist();
    scanf("%d%d",&n,&new);
    node* p=head->next;
    for(int i=1;i!=n-1&&n>1&&p;i++)
    {
        p=p->next;
    }
    if(n<=1||!p)
    {
        printf("输入不合法，或者插入超出界限\n");
        return -1;
    }
    node* insert=malloc(sizeof(node));
    insert->data=new;
    insert->next=p->next;
    p->next=insert;
    p=head->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}