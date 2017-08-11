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

struct node *create_node15(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
}

void insert_to_tree15(struct node **root,int data)
{
    if(!(*root))
        *root=create_node15(data);
    else
    {
        queue<struct node *> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
            {
                my_queue.push(temp->left);
            }
            else
            {
                temp->left=create_node15(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node15(data);
                break;
            }
        }
    }
    return;
}

void inorder15(struct node *root)
{
    if((root))
    {
        inorder15(root->left);
        printf("%d\t",root->data);
        inorder15(root->right);
    }
    return;
}
void print_paths(struct node *root,int *paths ,int path_len)
{
    //If we print path when the node is null it print the same
    //Path twice as left and right both null once for left and once for right
    if(!root)
        return;

    paths[path_len]=root->data;
    //When both left and right are null its a leaf
    //hence print paths
    if(!root->left && !root->right)
    {
        printf("\nPath->length\t%d\n",path_len);
        for(int i=0;i<=path_len;i++)
            printf("%d\t",paths[i]);
        printf("\n");
    }
    else
    {
        print_paths(root->left,paths,path_len+1);
        print_paths(root->right,paths,path_len+1);
    }
}
int test_main15()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree15(&tree_head,i*10);
    printf("In-Order\t\t\t");
    inorder15(tree_head);
    printf("\n");

    printf("Paths\n");
    int paths[10000];
    print_paths(tree_head,paths,0);
    return 0;
}
