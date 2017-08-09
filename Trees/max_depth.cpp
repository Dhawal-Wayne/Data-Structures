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

void enqueue10(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;
    if(*queue)
    {
        struct queue_node *temp=*queue;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }
    else
    {
        *queue=new_node;
    }
    return;
}

struct node * dequeue10(struct queue_node **queue)
{
    struct queue_node *result=NULL;
    if(*queue)
    {
        result=*queue;
        *queue=(*queue)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node * create_node10(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree10(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node10(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue10(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=dequeue10(&my_queue);
            if(temp->left)
            {
                enqueue10(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node10(data);
                break;
            }
            if(temp->right)
            {
                enqueue10(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node10(data);
                break;            }
        }
    }
    return ;
}

void inorder10(struct node *root)
{
    if(!root)
    {
        return;
    }

    inorder10(root->left);
    printf("%d\t",root->data);
    inorder10(root->right);
    return;
}
void postorder10(struct node *root)
{
    if(!root)
    {
        return;
    }

    postorder10(root->left);
    postorder10(root->right);
    printf("%d\t",root->data);
    return;
}
void preorder10(struct node *root)
{
    if(!root)
    {
        return;
    }

    printf("%d\t",root->data);
    preorder10(root->left);
    preorder10(root->right);
    return;
}

struct node * deepest_node(struct node *root)
{
    struct node *result=NULL;
    if(root)
    {
        struct queue_node *my_queue=NULL;
        enqueue10(&my_queue,root);
        while(my_queue)
        {
            struct node *temp=dequeue10(&my_queue);
            result=temp;
            if(temp->left)
                enqueue10(&my_queue,temp->left);
            if(temp->right)
                enqueue10(&my_queue,temp->right);
        }
    }
    return result;
}


int test_main10()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree10(&tree_head,i%100);
    }

    printf("INORDER\t\t\t");
    inorder10(tree_head);
    printf("\n");

    printf("POSTORDER\t\t");
    postorder10(tree_head);
    printf("\n");

    printf("PREORDER\t\t");
    preorder10(tree_head);
    printf("\n");

    printf("DEEPEST NODE IS %d\n",deepest_node(tree_head)->data);

    return 0;
}
