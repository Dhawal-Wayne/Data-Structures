#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node *right;
};

struct queue_node
{
    struct node *data;
    struct queue_node *next;
};

void enqueue12(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node =NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;
    if(!(*queue))
    {
        *queue=new_node;
    }
    else
    {
        struct queue_node *temp=NULL;
        temp=*queue;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }

    return ;
}

struct node * dequeue12(struct queue_node **queue)
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

struct node * create_node12(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree12(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node12(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue12(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=dequeue12(&my_queue);
            if(temp->left)
            {
                enqueue12(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node12(data);
                break;
            }
            if(temp->right)
            {
                enqueue12(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node12(data);
                break;
            }
        }
    }
    return;
}

void inorder12(struct node *root)
{
    if(root)
    {
        inorder12(root->left);
        printf("%d\t",root->data);
        inorder12(root->right);
    }
    return;
}

void delete_level_wise(struct node **root)
{
    if(*root)
    {
        struct queue_node *my_queue=NULL;
        enqueue12(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=dequeue12(&my_queue);
            if(temp->left)
                enqueue12(&my_queue,temp->left);
            if(temp->right)
                enqueue12(&my_queue,temp->right);
            free(temp);
        }
    }
    return ;
}


int test_main12()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree12(&tree_head,i*10+rand()%100);
    }
    printf("In-Order\t\t\t");
    inorder12(tree_head);

    printf("\nDeleting tree\n");
    delete_level_wise(&tree_head);


    if(!tree_head)
    {
        printf("NOT DELETED\n");
    }
    else
        printf("DELETED\n");
    return 0;
}
