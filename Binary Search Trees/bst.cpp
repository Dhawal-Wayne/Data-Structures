#include "bst.hpp"

struct node * create_node(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree(struct node **root,int data)
{
    if(!(*root))
        *root=create_node(data);
    else
    {
        if( (*root)->data < data)
            insert_to_tree(&(*root)->right,data);
        else
            insert_to_tree(&(*root)->left,data);
    }
    return;
}

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
