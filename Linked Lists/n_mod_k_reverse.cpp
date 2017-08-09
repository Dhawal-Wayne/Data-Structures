#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll15(int data,struct node **head)
{

    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return;
}

void print16(struct node *head)
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

struct node *find_last_n_mod_k_from_end(int k,struct node *head)
{
    struct node *traverse=NULL;
    struct node *result=NULL;

    traverse=head;

    int len=0;

    while(traverse)
    {
        len++;
        traverse=traverse->next;
    }

    if(len>k)
    {
        int counter=len%k;
        result=head;
        while(counter)
        {
            counter--;
            result=result->next;
        }
    }

    return result;
}


int test_main15()
{
    struct node *head=NULL;
    int n=10,k=11;

    for(int i=0;i<n;i++)
    {
        insert_ll15(i*10+9,&head);
    }

    printf("Original List\t");
    print16(head);

    struct node *last_from_last_n_mod_k=NULL;
    last_from_last_n_mod_k=find_last_n_mod_k_from_end(k,head);

    if(last_from_last_n_mod_k)
    {
        printf("Last n mod k from end is %d\n",last_from_last_n_mod_k->data);
    }
    else
    {
        printf("Invalid Input\n");
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
