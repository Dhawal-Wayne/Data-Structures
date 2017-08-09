#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node1(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=data;

    return new_node;

}

void inorder1(struct node *root)
{
    if(!root)
        return;
    inorder1(root->left);
    printf("%d\t",root->data);
    inorder1(root->right);
    return;
}

void insert_to_tree1(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node1(data);
    }
    else
    {
        if((*root)->data > data)
        {
            insert_to_tree1(&(*root)->right,data);
        }
        else
        {
            insert_to_tree1(&(*root)->left,data);
        }
    }
    return;
}

void find_max_of_tree(struct node* root,int *max_element)
{
    if(!(root));
    else
    {
        if(root->left && *max_element<root->left->data)
            *max_element=root->left->data;
        if(root->right && *max_element<root->right->data)
            *max_element=root->right->data;
        if(*max_element<root->data)
            *max_element=root->data;
        find_max_of_tree(root->left,max_element);
        find_max_of_tree(root->right,max_element);
    }
    return;
}

int test_main1()
{
    struct node *tree_root=NULL;
    for(int i=0;i<100;i++)
    {
        insert_to_tree1(&tree_root,i*rand()%67+11);
    }
    printf("Inorder\t");
    inorder1(tree_root);
    printf("\n");

    int max_element=-100000;
    find_max_of_tree(tree_root,&max_element);
    printf("Max Element is %d",max_element);
    return 0;
}
