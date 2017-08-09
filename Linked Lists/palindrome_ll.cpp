#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_ll10(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
    return ;
}

void print10(struct node *head)
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

struct node * reverse_ll10(struct node *head)
{
    struct node *reverse_list=NULL;
    struct node *temp=head;
    while(temp)
    {
        struct node *temp1=temp->next;
        temp->next=reverse_list;
        reverse_list=temp;
        temp=temp1;
    }
    return reverse_list;
}

int is_palindrome(struct node *head)
{
    struct node *first_half=NULL,*second_half=NULL;
    struct node *mid_point=NULL,*last_point=NULL;
    mid_point=head;
    last_point=head;

    int counter=0;

    while(last_point && last_point->next && last_point->next->next)
    {
        mid_point=mid_point->next;
        last_point=last_point->next->next;
        counter++;
    }

    first_half=head;
    second_half=mid_point;

    if(last_point && last_point->next)
    {
        second_half=mid_point->next;
    }

    second_half=reverse_ll10(second_half);

    while(counter)
    {
        if(second_half->data!=first_half->data)
        {
            break;
        }
        second_half=second_half->next;
        first_half=first_half->next;
        counter--;
    }

    if(counter==0)
        return 1;

    return 0;
}

int test_main10()
{
    struct node *head=NULL;
    int input_arr[]={11,22,33,33,22,11};
    int n=6;
    for(int i=0;i<n;i++)
    {
        insert_ll10(input_arr[i],&head);
    }

    printf("Input is:\t");
    print10(head);

    if(is_palindrome(head))
    {
        printf("Is a Palindrome\n");
    }
    else
    {
        printf("Not a Palindrome\n");
    }

    return 0;
}
