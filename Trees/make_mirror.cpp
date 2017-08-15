#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node *right;
};

struct node * create_node17(int data)
{
    struct node * new_node =NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree17(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node17(data);
    }
    else
    {
        queue<struct node *> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
                my_queue.push(temp->left);
            else
            {
                temp->left=create_node17(data);
                break;
            }
            if(temp->right)
                my_queue.push(temp->right);
            else
            {
                temp->right=create_node17(data);
                break;
            }
        }
    }
    return ;
}

void inorder17(struct node *root)
{
    if(root)
    {
        inorder17(root->left);
        printf("%d\t",root->data);
        inorder17(root->right);
    }
    return;
}

void make_mirror(struct node *root)
{
    if(root)
    {
        struct node *temp=NULL;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        make_mirror(root->left);
        make_mirror(root->right);
    }
}

int test_main17()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree17(&tree_head,i*10);
    }
    printf("IN-Order\t\t\t");
    inorder17(tree_head);
    printf("\n");

    make_mirror(tree_head);

    printf("After mirror\n");
    printf("IN-Order\t\t\t");
    inorder17(tree_head);
    printf("\n");
    return 0;
}
