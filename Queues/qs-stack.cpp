#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct stack_of_2_queues
{
    struct node *queue_1;
    struct node *queue_2;
};

void enqueue3(struct node **my_queue,struct node *new_node)
{
    if(*my_queue)
    {
        struct node *temp=*my_queue;
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

struct node * dequeue3(struct node **my_queue)
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

void push3(struct stack_of_2_queues **my_stack,int data)
{
    struct node * new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->next=NULL;
    new_node->data=data;

    if((*my_stack)->queue_1)
    {
        while((*my_stack)->queue_1)
        {
            enqueue3(&(*my_stack)->queue_2,dequeue3(&(*my_stack)->queue_1));
        }

        enqueue3(&(*my_stack)->queue_1,new_node);

        while((*my_stack)->queue_2)
        {
            enqueue3(&(*my_stack)->queue_1,dequeue3(&(*my_stack)->queue_2));
        }
    }
    else
    {
        enqueue3(&(*my_stack)->queue_1,new_node);
    }

    return ;
}

struct node * pop3(struct stack_of_2_queues **my_stack)
{
    struct node *result=NULL;
    if((*my_stack)->queue_1)
    {
        result=dequeue3(&(*my_stack)->queue_1);
    }
    return result;
}

int test_main3()
{
    struct stack_of_2_queues *my_stack=NULL;
    my_stack=(struct stack_of_2_queues*)calloc(1,sizeof(struct stack_of_2_queues));
    my_stack->queue_1=NULL;
    my_stack->queue_2=NULL;

    for(int i=1;i<6;i++)
    {
        printf("Push\t%d\n",i*10);
        push3(&my_stack,i*10);
    }

    printf("\n");

    for(int i=0;i<5;i++)
    {
        printf("Pop\t%d\n",pop3(&my_stack)->data);
    }

    return 0;
}
