#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};


void push3(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return ;
}

struct node *pop3(struct node **head)
{
    struct node *top_of_stack=NULL;
    if(*head)
    {
        top_of_stack=*head;
        *head=(*head)->next;
    }
    return top_of_stack;
}

void print3(struct node *head)
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

int top_of_stack3(struct node *head)
{
    if(head)
    {
        return (head)->data;
    }
    return -1;
}

int * find_stock_span(int stocks[],int n)
{
    struct node *span_stack=NULL;
    struct node *stock_stack=NULL;

    int *spans=(int *)calloc(n,sizeof(int));

    push3(1,&span_stack);

    push3(stocks[0],&stock_stack);

    spans[0]=1;


    for(int i=1;i<n;i++)
    {
        int counter=1;
        while(top_of_stack3(stock_stack)!=-1 && top_of_stack3(stock_stack)<stocks[i])
        {
            pop3(&stock_stack);
            counter+=top_of_stack3(span_stack);
            pop3(&span_stack);
        }
        push3(stocks[i],&stock_stack);
        push3(counter,&span_stack);
        spans[i]=counter;
    }

    return spans;
}

int test_main3()
{
    int *spans=NULL;
    int stocks[]={2,5,4,6,7};
    int n=sizeof(stocks)/sizeof(stocks[0]);

    spans=find_stock_span(stocks,n);

    printf("Span are\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",spans[i]);
    }
    printf("\n");
    return 0;
}
