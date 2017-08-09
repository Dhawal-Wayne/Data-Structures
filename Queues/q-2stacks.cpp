#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue_of_2_stacks
{
    struct node *stack_1;
    struct node *stack_2;
};

void push2(struct node **head,struct node *new_node)
{
    new_node->next=*head;
    *head=new_node;
    return ;
}

struct node * pop2(struct node **head)
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

void enqueue2(struct queue_of_2_stacks **my_queue,int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;


    if((*my_queue)->stack_1)
    {
        while((*my_queue)->stack_1)
        {
            push2(&(*my_queue)->stack_2,pop2(&(*my_queue)->stack_1));
        }

        push2(&(*my_queue)->stack_1,new_node);

        while((*my_queue)->stack_2)
        {
            push2(&(*my_queue)->stack_1,pop2(&(*my_queue)->stack_2));
        }
    }
    else
        (*my_queue)->stack_1=new_node;

    return;
}

struct node * dequeue2(struct queue_of_2_stacks **my_queue)
{
    struct node *result=NULL;
    if(*my_queue)
    {
        result=(*my_queue)->stack_1;
        (*my_queue)->stack_1=((*my_queue)->stack_1)->next;
        result->next=NULL;
    }
    return result;
}

int test_main2()
{
    struct queue_of_2_stacks *my_queue;
    my_queue=(struct queue_of_2_stacks*)calloc(1,sizeof(struct queue_of_2_stacks));
    my_queue->stack_1=NULL;
    my_queue->stack_2=NULL;
    for(int i=1;i<6;i++)
    {
        if(i%2)
        {
            printf("Enqueue\t%d\n",i*10);
            enqueue2(&my_queue,i*10);
        }
        else
        {
            struct node *result=NULL;
            if((result=dequeue2(&my_queue)))
                printf("Dequeue\t%d\n",result->data);
            else
                printf("Already empty\n");
        }
    }
}
