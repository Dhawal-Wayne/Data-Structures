#include <stdio.h>

#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue1(struct node **my_queue,struct node *new_node)
{
    struct node *temp=NULL;
    temp=*my_queue;
    if(temp)
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    else
        *my_queue=new_node;
    return;
}

struct node* dequeue1(struct node **my_queue)
{
    struct node *result=NULL;
    if(*my_queue)
    {
        result=*my_queue;
        *my_queue=(*my_queue)->next;
        result->next=NULL;
    }
    return result;
}

struct node * pop1(struct node **head)
{
    struct node *result=NULL;
    if(*head)
    {
        result=*head;
        *head=(*head)->next;
        result->next=NULL;
    }
    return result;
}

void push1(struct node **head,struct node *new_node)
{

    new_node->next=*head;
    *head=new_node;
    return ;
}

void q_rev1(struct node **my_queue)
{
    struct node *temp_stack=NULL;
    while(*my_queue)
    {
        push1(&temp_stack,dequeue1(my_queue));
    }
    while(temp_stack)
    {
        enqueue1(my_queue,pop1(&temp_stack));
    }
}

void print_queue1(struct node *head)
{
    printf("Queues:\t");
    while(head)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}

int test_main1()
{
    struct node *my_queue=NULL;
    for(int i=1;i<6;i++)
    {
        struct node *new_node=NULL;
        new_node=(struct node *)calloc(1,sizeof(struct node));
        new_node->data=i;
        new_node->next=NULL;
        enqueue1(&my_queue,new_node);
    }
    print_queue1(my_queue);
    q_rev1(&my_queue);
    print_queue1(my_queue);
    return 0;
}
