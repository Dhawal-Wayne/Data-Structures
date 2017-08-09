#include <cstdio>
#include <cstdlib>
#include<iostream>

using namespace std;

struct node {
    int data;
    struct node * next;
};

void insert_ll2(int data,struct node **head)
{
    struct node *temp;
    temp=(struct node *)calloc(1,sizeof(struct node));
    temp->next=*head;
    temp->data=data;
    *head=temp;
}

int find_nth(struct node *head,int n)
{
    if(n>0)
    {
        int counter=1;
        struct node *nth_temp=head,*temp=head;
        while(temp)
        {
            if(counter>n)
            {
                nth_temp=nth_temp->next;
            }
            temp=temp->next;
            counter++;
        }
        return nth_temp->data;
    }
    else{
        return -1;
    }
}

void print2(struct node *head)
{
    struct node *temp;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int test_main2()
{
    struct node *head;
    head=NULL;
    int max_val=10;
    for(int i=0;i<max_val;i++)
    {
        insert_ll2(i,&head);
    }
    cout<<"Values present"<<endl;
    print2(head);
    int n=4;
    cout<<"list entery "<<n<<" from last"<<endl;
    cout<<find_nth(head,n);

    for(int i=0;i<max_val;i++)
    {
        struct node *temp;
        temp=head->next;
        free(head);
        head=temp;
    }
    free(head);
    return 0;
}
