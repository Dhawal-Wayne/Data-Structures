#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue_node
{
    struct node *data;
    struct queue_node *next;
};

struct stack_node
{
    struct node *data;
    struct stack_node *next;
};

void push4(struct stack_node **head,struct node *data)
{
    struct stack_node *new_node=NULL;
    new_node=(struct stack_node*)calloc(1,sizeof(struct stack_node));
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;

    return;
}

struct node * pop4(struct stack_node **head)
{
    struct stack_node *result=NULL;
    if(*head)
    {
        result=*head;
        *head=(*head)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

void enqueue4(struct queue_node **head,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;
    if(*head)
    {
        struct queue_node *temp=NULL;
        temp=*head;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }
    else
    {
        *head=new_node;
    }
}

struct node * dequeue4(struct queue_node **head)
{
    if(*head)
    {
        struct queue_node *new_node=NULL;
        new_node=*head;
        *head=(*head)->next;
        new_node->next=NULL;
        return new_node->data;
    }
    return NULL;
}

struct node * create_node4(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree4(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node4(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue4(&my_queue,*root);
       // printf("\nTree is \t");
        while(my_queue)
        {
            struct node *temp=dequeue4(&my_queue);
            //printf("%d\t",temp->data);
            if(temp->left)
                enqueue4(&my_queue,temp->left);
            else
            {
                temp->left=create_node4(data);
                break;
            }
            if(temp->right)
                enqueue4(&my_queue,temp->right);
            else
            {
                temp->right=create_node4(data);
                break;
            }
        }
    }
    return;
}

void reverse_level_order_tree(struct node *root)
{
    if(!root)
        return;
    struct stack_node *my_stack=NULL;
    struct queue_node *my_queue=NULL;
    enqueue4(&my_queue,root);
    while(my_queue)
    {
        struct node *temp=dequeue4(&my_queue);
        if(temp->left)
            enqueue4(&my_queue,temp->left);
        if(temp->right)
            enqueue4(&my_queue,temp->right);
        push4(&my_stack,temp);
    }

    printf("\nLEVEL ORDER IN REVERSE IS\t");
    while(my_stack)
    {
        printf("%d\t",pop4(&my_stack)->data);
    }

    return;
}

void inorder4(struct node *root)
{
    if(!root)
        return;
    inorder4(root->left);
    printf("%d\t",root->data);
    inorder4(root->right);

    return;
}

void preorder4(struct node *root)
{
    if(!root)
        return;
    printf("%d\t",root->data);
    preorder4(root->left);
    preorder4(root->right);

    return;
}

int test_main4()
{
    struct node *tree_head=NULL;
    int n=500;
    for(int i=0;i<n;i++)
        insert_to_tree4(&tree_head,i+rand()%100);

    //printf("\nInorder\t\t\t\t");
    //inorder4(tree_head);

    //printf("\nPre-order\t\t\t");
    //preorder4(tree_head);

    reverse_level_order_tree(tree_head);
    return 0;
}
