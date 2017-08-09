#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push1(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return;
}

struct node* pop1(struct node **head)
{
    struct node *result=NULL;

    if(*head)
    {
        result=*head;
        *head=(*head)->next;
    }

    return result;
}

int top_of_stack1(struct node *head)
{
    if(head)
        return head->data;
    else
        return 99999999;
}

void print_stack1(struct node *head)
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

int test_main1()
{
    struct node *main_stack=NULL,*min_stack=NULL;

    int n=8;

    int arr[]={4,7,4,4,7,7,10,2};

    for(int i=0;i<n;i++)
    {
        int input_element=arr[i];
        push1(input_element,&main_stack);
        if(input_element<=top_of_stack1(min_stack))
            push1(input_element,&min_stack);
    }

    cout<<"Main Stack is\t";
    print_stack1(main_stack);
    cout<<"MIN Stack is\t";
    print_stack1(min_stack);

    for(int i=0;i<5;i++)
    {
        struct node *top_of_main_stack=NULL;
        top_of_main_stack=pop1(&main_stack);
        if(top_of_main_stack->data==top_of_stack1(min_stack))
        {
            pop1(&min_stack);
            cout<<"After pop\t";
            print_stack1(min_stack);
        }
    }
}
