#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

struct node
{
    int data;
    struct node *next;
};


struct node *merge_point=NULL;

struct node* insert_ll6(int data,struct node **head)
{
    struct node *temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=data;
    temp->next=*head;
    *head=temp;
    return temp;
}

void find_merging_point(struct node *head1,struct node *head2)
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    int length_of_list1=0,length_of_list2=0;
    while(temp1)
    {
        length_of_list1++;
        temp1=temp1->next;
    }
    while(temp2)
    {
        length_of_list2++;
        temp2=temp2->next;
    }
    int diff=abs(length_of_list1-length_of_list2);

    struct node *longer_list=NULL,*shorter_list=NULL;

    if(length_of_list1>length_of_list2)
    {
        longer_list=head1;
        shorter_list=head2;
    }
    else
    {
        longer_list=head2;
        shorter_list=head1;
    }
    while(diff>0)
    {
        longer_list=longer_list->next;
        diff--;
    }
    while(1)
    {
        if(shorter_list==longer_list)
        {
            printf("Merging point is %d ---> %d\n",shorter_list->data,shorter_list);
            break;
        }
        longer_list=longer_list->next;
        shorter_list=shorter_list->next;
    }
}

int test_main()
{
    struct node *head1=NULL,*head2=NULL;
    for(int i=0;i<6;i++)
    {
        merge_point=insert_ll6(i*10,&head1);
    }
    struct node *list_end=NULL;
    for(int i=0;i<6;i++)
    {
        list_end=insert_ll6(i*20,&head2);
    }
    printf("Merged at %d\n",merge_point->data);
    list_end->next=merge_point;
    for(int i=0;i<7;i++)
    {
        insert_ll6(i*30,&(list_end->next));
    }
    find_merging_point(head1,head2);
    return 0;
}
