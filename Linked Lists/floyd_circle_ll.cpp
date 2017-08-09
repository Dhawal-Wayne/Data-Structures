#include <iostream>
#include <cstdio>
#include <cstdlib>

struct node
{
    int data;
    struct node *next;
};

struct node *point_of_circle;

struct node* insert_ll3(int data,struct node **head)
{
    struct node *temp=*head;
    struct node* temp2=(struct node *)calloc(1,sizeof(struct node));
    if(temp)
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp2->data=data;
        temp2->next=temp->next;
        temp->next=temp2;
    }
    else
    {
        temp2->data=data;
        temp2->next=*head;
        *head=temp2;
    }
    return temp2;
}

int has_cycle(struct node *head)
{
    int result=0;
    struct node * slow_pointer=head,*fast_pointer=head;
    while(slow_pointer && fast_pointer && fast_pointer->next)
    {
        slow_pointer=slow_pointer->next;
        fast_pointer=fast_pointer->next->next;
        if(slow_pointer==fast_pointer)
        {
            slow_pointer=head;
            while(slow_pointer!=fast_pointer)
            {
                fast_pointer=fast_pointer->next;
                slow_pointer=slow_pointer->next;
            }
            result=fast_pointer->data;

            int length_of_cycle=0;

            do
            {
                fast_pointer=fast_pointer->next;
                length_of_cycle++;
            }while(fast_pointer!=slow_pointer);

            printf("Length of cycle %d\n",length_of_cycle);

            break;
        }
    }
    return result;
}

int test_main3()
{
    struct node *head=NULL;
    struct node *node_val;
    for(int i=0;i<20;i++)
    {
        node_val=insert_ll3(i*10,&head);
        if(i==12)
        {
            point_of_circle=node_val;
            printf("Cycle created at %d\n",point_of_circle->data);
        }
    }
    node_val->next=point_of_circle;
    int result=0;
    if((result=has_cycle(head)))
    {
        printf("Cycle detected at %d\n",result);
    }
    else{
        printf("NO CYCLE\n");
    }
    return 0;
}
