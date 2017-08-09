#include<cstdio>
#include <iostream>
#include <cstdlib>

struct node
{
    int data;
    struct node *next;
};

void insert_ll5(int data,struct node **head)
{
    struct node *temp;
    temp=(struct node *)calloc(1,sizeof(struct node ));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}


void find_mid(struct node *head)
{
    struct node *temp1,*temp2;
    temp1=head;
    temp2=head;
    while(temp2->next && temp2->next->next)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
    }

    if(temp2->next)
    {
        printf("Middle elements are %d\t%d\n",temp1->data,temp1->next->data);
        return ;
    }
    else
    {
        printf("Middle element is %d\n",temp1->data);
        return;
    }
}

void print5(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int test_main5()
{
    struct node *head=NULL;
    for(int i=0;i<9;i++)
    {
        insert_ll5(i*10,&head);
    }
    print5(head);
    find_mid(head);
    while(head)
    {
        struct node *temp=head->next;
        free(head);
        head=temp;
    }
    return 0;
}
