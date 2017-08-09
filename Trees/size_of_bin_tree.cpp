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

void enqueue3(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node *)calloc(1,sizeof(struct queue_node));
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
    {
        *queue=new_node;
    }
}

struct node * dequeue3(struct queue_node **queue)
{
    struct queue_node *result=NULL;

    result=*queue;
    *queue=(*queue)->next;
    result->next=NULL;

    return result->data;
}

struct node *create_node3(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree3(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node3(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue3(&my_queue,*root);
        while(my_queue)
        {
            struct node * temp=dequeue3(&my_queue);
            if(temp->left)
            {
                enqueue3(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node3(data);
                break;
            }
            if(temp->right)
            {
                enqueue3(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node3(data);
                break;
            }
        }
    }
    return;
}

void inorder3(struct node *root)
{
    if(!root)
        return;
    inorder3(root->left);
    printf("%d\t",root->data);
    inorder3(root->right);
    return;
}

void postorder3(struct node *root)
{
    if(!root)
        return;
    postorder3(root->left);
    postorder3(root->right);
    printf("%d\t",root->data);
    return;
}

int size_of_binary_tree_recursive(struct node *root)
{
    if(!root)
        return 0;
    //Simply Adding the number of nodes in the tree.
    return size_of_binary_tree_recursive(root->left)+1+size_of_binary_tree_recursive(root->right);
}

int size_of_binary_tree_non_recursive(struct node *root)
{
    struct queue_node *queue=NULL;
    enqueue3(&queue,root);
    int size_of_queue=0;
    //Visiting All Nodes implies finding size
    if(root)
    while(queue)
    {
        struct node *temp=dequeue3(&queue);
        size_of_queue++;
        if(temp->left)
            enqueue3(&queue,temp->left);
        if(temp->right)
            enqueue3(&queue,temp->right);
    }
    return size_of_queue;
}

int test_main3()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
    {
        insert_to_tree3(&tree_head,i+rand()%100);
    }
    printf("In-order\t");
    inorder3(tree_head);
    printf("\n");

    printf("Postorder\t");
    postorder3(tree_head);
    printf("\n");

    printf("Size of tree in recursive-approach\t\t%d\n",size_of_binary_tree_recursive(tree_head));
    printf("Size of tree in non-recursive-approach\t\t%d\n",size_of_binary_tree_non_recursive(tree_head));

    return 0;
}
