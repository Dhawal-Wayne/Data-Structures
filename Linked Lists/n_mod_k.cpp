#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll14(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return;
}

struct node * find_last_n_mod_k(int k,struct node *head)
{
    struct node *traverser=NULL;
    struct node *result=NULL;

    traverser=head;

    int counter=0;

    while(traverser)
    {
        counter++;
        if(counter%k==0)
            result=traverser;

        traverser=traverser->next;
    }
    return result;
}


void print14(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}

int test_main14()
{
    struct node *head=NULL;
    int n=14,k=11;

    for(int i=0;i<n;i++)
    {
        insert_ll14(i*10+5,&head);
    }

    printf("Original List\t");
    print14(head);

    struct node *last_n_mod_k=NULL;
    last_n_mod_k=find_last_n_mod_k(k,head);

    if(last_n_mod_k)
    {
        printf("Last n mod k is %d\n",last_n_mod_k->data);
    }
    else
    {
        printf("Invalid input\n");
    }

    for(int i=0;i<n;i++)
    {
        struct node *temp=NULL;
        temp=head->next;
        free(head);
        head=temp;
    }
    return 0;
}
