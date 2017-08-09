#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push2(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return ;
}

struct node* pop2(struct node **head)
{
    struct node *result=NULL;

    if(*head)
    {
        result=*head;
        *head=(*head)->next;
    }

    return result;
}

void print2(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void push_to_end(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    if(*head)
    {
        struct node *temp=NULL;
        temp=*head;
        while(temp->next)
        {
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    else
    {
        new_node->next=*head;
        *head=new_node;
    }

    return;
}

void push_in_reverse(struct node **head)
{
    struct node *temp=NULL;
    struct node **new_head=NULL;

    if(*head)
    {
        temp=pop2(head);
        //Already Popped so no need to do a *head->next
        push_in_reverse(&(*head));
        push_to_end(temp->data,head);
    }
    return;
}

int test_main2()
{
    struct node * head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
    {
        push2(i*10+1,&head);
    }
    cout<<"Original\t";
    print2(head);

    cout<<"After reverse\t";
    push_in_reverse(&head);
    print2(head);

    return 0;
}
