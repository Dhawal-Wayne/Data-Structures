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

void enqueue2(struct queue_node **head,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=NULL;
    if((*head))
    {
        struct queue_node *temp=*head;
        while(temp->next)
            temp=temp->next;
        temp->next=new_node;
    }
    else
    {
        *head=new_node;
    }
    return;
}

struct node* dequeue2(struct queue_node **head)
{
    struct queue_node *result=NULL;
    if(*head)
    {
        result=*head;
        *head=(*head)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node * create_node2(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void insert_to_tree2(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node2(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        struct node *temp=NULL;
        enqueue2(&my_queue,*root);
        while(my_queue)
        {
            temp=dequeue2(&my_queue);
            if(temp->left)
            {
                enqueue2(&my_queue,temp);
            }
            else
            {
                temp->left=create_node2(data);
                break;
            }
            if(temp->right)
            {
                enqueue2(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node2(data);
                break;
            }
        }
    }
    return;
}

void inorder2(struct node *root)
{
    if(!root)
        return;
    inorder2(root->left);
    printf("%d\t",root->data);
    inorder2(root->right);
    return;
}

void postorder2(struct node *root)
{
    if(!root)
        return;
    postorder2(root->left);
    postorder2(root->right);
    printf("%d\t",root->data);
    return;
}

int test_main2()
{
    struct node *tree_head=NULL;
    int n=11;
    for(int i=0;i<n;i++)
    {
        insert_to_tree2(&tree_head,rand()%100+11);
    }
    printf("In-order\t");
    inorder2(tree_head);
    printf("\n");

    printf("Postorder\t");
    postorder2(tree_head);
    printf("\n");
    return 0;
}
