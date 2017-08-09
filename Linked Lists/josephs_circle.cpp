#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll12(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;

    struct node *temp=*head;

    if(*head)
    {

        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
    else
        *head=new_node;

    new_node->next=*head;


    return;
}

void print12(struct node *head)
{
    struct node *temp=NULL;
    temp=head;

    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
    return;
}

struct node * josephus_circle_game(struct node *head,int m)
{
    int counter=0;
    struct node *cur=NULL;
    struct node *prev=NULL;
    cur=head;

    if(head)
    do
    {
        counter++;
        if(counter%m==m-1)
        {
            struct node *temp=NULL;
            temp=cur->next;
            cur->next=cur->next->next;
            printf("Eliminating %d\n",temp->data);
            free(temp);
            counter=0;
        }
        prev=cur;
        cur=cur->next;
    }while(cur!=prev);
    else
        return NULL;

    return cur;
}

int test_main12()
{
    struct node *head=NULL;
    int n=6;
    int m=3;
    for(int i=1;i<n+1;i++)
    {
        insert_ll12(i,&head);
    }
    printf("Original List\t");
    print12(head);
    struct node *josephus_position=josephus_circle_game(head,m);
    if(josephus_position)
    printf("Winner is\t%d\n",josephus_position->data);
    else
    {
        printf("Invalid input\n");
    }
    return 0;
}
