#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void pre_queue(struct node **my_queue,int data)
{
    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;

    if(*my_queue)
    {
        struct node *temp=NULL;
        temp=*my_queue;
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

/**<
void push4(struct node **head,struct node *new_node)
{
    new_node=*head;
    *head=new_node;
    return;
}

struct node * pop4(struct node **head)
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
 */

void enqueue4(struct node **head,struct node *new_node)
{
    if(*head)
    {
        struct node *temp=*head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    else
    {
        *head=new_node;
    }
    return;
}

struct node * dequeue4(struct node **head)
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

int size_of_queue(struct node *my_queue)
{
    int len_of_queue=0;
    while(my_queue)
    {
        len_of_queue++;
        my_queue=my_queue->next;
    }
    return len_of_queue;
}

void half_queue_club(struct node **my_queue)
{
    struct node *temp_queue=NULL;

    int len_of_queue=size_of_queue(*my_queue);

    if(len_of_queue%2)
        return;
    else
    {
        int hal_size=0;
        while(hal_size!=len_of_queue/2)
        {
            enqueue4(&temp_queue,dequeue4(my_queue));
            hal_size++;
        }
        struct node *final_queue=NULL;
        while(len_of_queue)
        {
            if(! (len_of_queue%2))
                enqueue4(my_queue,dequeue4(&temp_queue));
            else
                enqueue4(my_queue,dequeue4(my_queue));
            len_of_queue--;
        }
    }

    return;
}

int test_main4()
{
    struct node *my_queue=NULL;
    for(int i=1;i!=11;i++)
    {
        pre_queue(&my_queue,i+10);
    }
    half_queue_club(&my_queue);

    printf("Dequeue\t");
    for(int i=0;i<10;i++)
    {
        printf("%d\t",dequeue4(&my_queue)->data);
    }

    return 0;
}
