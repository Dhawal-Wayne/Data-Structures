#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *rand_pointer;
};

void insert_ll13(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    new_node->rand_pointer=*head;
    *head=new_node;
    return ;
}

void print13(struct node *head)
{
    struct node *temp=NULL;

    temp=head;
    printf("NEXT POINTERS MOVEMENT\t");
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");

    temp=head;
    printf("RAND POINTERS MOVEMENT\t");
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->rand_pointer;
    }
    printf("\n");
}

struct node * clone_ll(struct node * head)
{
    struct node *head_2=NULL;
    struct node *temp=NULL;
    temp=head;
    while(temp)
    {
        struct node *next_node=temp->next;
        struct node *dup_node=NULL;
        dup_node=(struct node *)calloc(1,sizeof(struct node));
        dup_node->data=temp->data;
        dup_node->next=next_node;
        temp->next=dup_node;
        temp=next_node;
    }

    temp=head;
    head_2=head->next;

    while(temp->next && temp->rand_pointer)
    {
        struct node *next_node=temp->next->next;
        temp->next->rand_pointer=temp->rand_pointer->next;
        temp->next->next=next_node->next;
        temp=next_node;
    }

    return head_2;
}

int test_main13()
{
    struct node *head=NULL;
    int n=10;
    for(int i=0;i<10;i++)
    {
        insert_ll13(i*7+1,&head);
    }

    printf("Original List\n");
    print13(head);

    printf("Cloned List\n");
    print13(clone_ll(head));
    return 0;
}
