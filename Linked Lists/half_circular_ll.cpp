#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *last;

void insert_ll8(int data,struct node **head)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;

    if(*head)
    {
        struct node *temp=NULL;
        temp=*head;

        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }

    else
    {
        *head=new_node;
    }

    new_node->next=*head;

    return ;
}

void print8(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    if(head)
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n\n\n\n");
}

void half_circular_ll(struct node *head,struct node **cir_head_1,struct node **cir_head_2)
{
    struct node *mid=NULL,*last=NULL;
    mid=head,last=head;

    int turn=0;
    if(head)
    while(last->next!=head)
    {
        last=last->next;

        if(turn%2)
        mid=mid->next;

        turn++;
    }

    *cir_head_1=head;
    *cir_head_2=mid->next;

    last->next=mid->next;
    mid->next=head;

    return;
}

int test_main8()
{
    struct node *head=NULL;

    int n=11;

    for(int i=0;i<n;i++)
    {
        insert_ll8(i*10+1,&head);
    }
    printf("Original Circular Linked List\n");
    print8(head);

    struct node *cir_ll_1=NULL,*cir_ll_2=NULL;

    half_circular_ll(head,&cir_ll_1,&cir_ll_2);

    printf("First Half\n");
    print8(cir_ll_1);

    printf("Second Half\n");
    print8(cir_ll_2);

    for(int i=0;i<n;i++)
    {
        struct node *temp=NULL;
        temp=head->next;
        free(head);
        head=temp;
    }

    return 0;
}
