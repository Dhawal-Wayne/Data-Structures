#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node14(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree14(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node14(data);
    }
    else
    {
        queue<struct node*> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node * temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
            {
                my_queue.push(temp->left);
            }
            else
            {
                temp->left=create_node14(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node14(data);
                break;
            }
        }
    }
    return;
}

void inorder14(struct node *root)
{
    if(root)
    {
        inorder14(root->left);
        printf("%d\t",root->data);
        inorder14(root->right);
    }
    return;
}

int sum_of_all_nodes(struct node *root)
{
    int result=0;
    queue<struct node*> my_queue;
    my_queue.push(root);
    while(!my_queue.empty())
    {
        struct node *temp=my_queue.front();
        my_queue.pop();
        if(temp->left)
            my_queue.push(temp->left);
        if(temp->right)
            my_queue.push(temp->right);
        result+=temp->data;
    }
    return result;
}

int test_main14()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
    {
        insert_to_tree14(&tree_head,i*10);
    }
    printf("In-Order\t\t\t");
    inorder14(tree_head);
    printf("\n");
    printf("Sum of All Node is %d\n",sum_of_all_nodes(tree_head));
    return 0;
}
