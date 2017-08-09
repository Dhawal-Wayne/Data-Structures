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

void enqueue9(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;

    if(!(*queue))
    {
        new_node->next=NULL;
    }
    else
    {
        struct queue_node *temp=*queue;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }

    return;
}

struct node * dequeue9(struct queue_node **queue)
{
    struct queue_node *result=NULL;
    if((*queue))
    {
        result=*queue;
        *queue=(*queue)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node *create_node9(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void insert_to_tree9(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node9(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue9(&my_queue,*root);
        while(my_queue)
        {
            struct node *temp=NULL;
            temp=dequeue9(&my_queue);
            if(temp->left)
            {
                enqueue9(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node9(data);
                break;
            }
            if(temp->right)
            {
                enqueue9(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node9(data);
                break;
            }
        }
    }
    return;
}

void inorder9(struct node *root)
{
    if(!root)
        return;
    inorder9(root->left);
    printf("%d\t",root->data);
    inorder9(root->right);

    return;
}

bool structurally_equal(struct node *root_1,struct node *root_2)
{
    if(!root_1 && !root_2)
        return 1;
    if(!root_1 || !root_2)
        return 0;
    return (root_1->data==root_2->data)&&structurally_equal(root_1->left,root_2->left)&&structurally_equal(root_1->right,root_2->left);
}

int test_main9()
{
    int n=10;
    struct node *tree_head_1=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree9(&tree_head_1,i+rand()%100);

    struct node *tree_head_2=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree9(&tree_head_2,i+rand()%100);

    printf("Structurally equal : %d\n",structurally_equal(tree_head_1,tree_head_1));
    printf("Structurally equal : %d\n",structurally_equal(tree_head_1,tree_head_2));
    printf("Structurally equal : %d\n",structurally_equal(tree_head_2,tree_head_2));
    return 0;
}
