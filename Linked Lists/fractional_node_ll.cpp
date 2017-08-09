#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll_16(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return;
}

void print15(struct node *head)
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

