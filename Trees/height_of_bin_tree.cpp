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

void enqueue5(struct queue_node **queue,struct node* data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;
    if(*queue)
    {
        struct queue_node *temp=NULL;
        temp=*queue;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }
    else
        *queue=new_node;
    return;
}

struct node *dequeue5(struct queue_node **queue)
{
    if(*queue)
    {
        struct queue_node *result=NULL;
        result=*queue;
        *queue=(*queue)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node * create_node5(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree5(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node5(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue5(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=dequeue5(&my_queue);
            if(temp->left)
                enqueue5(&my_queue,temp->left);
            else
            {
                temp->left=create_node5(data);
                break;
            }
            if(temp->right)
                enqueue5(&my_queue,temp->right);
            else
            {
                temp->right=create_node5(data);
                break;
            }
        }
    }
    return;
}

int height_of_bin_tree(struct node *root)
{
    if(!root)
    {
        return 0;
    }

    int left_height=height_of_bin_tree(root->left);
    int right_height=height_of_bin_tree(root->right);
    return left_height>right_height ? left_height+1: right_height+1;
}

int test_main5()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree5(&tree_head,i+rand()%113);
    }
    printf("Height of tree\t%d\n",height_of_bin_tree(tree_head));
    return 0;
}
