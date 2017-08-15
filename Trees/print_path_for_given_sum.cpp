#include <stdio.h>
#include <stdlib.h>

#include <queue>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node16(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void insert_to_tree16(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node16(data);
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
                temp->left=create_node16(data);
                break;
            }
            if(temp->right)
                my_queue.push(temp->right);
            else
            {
                temp->right=create_node16(data);
                break;
            }
        }
    }
    return;
}

void inorder16(struct node *tree)
{
    if(tree)
    {
        inorder16(tree->left);
        printf("%d\t",tree->data);
        inorder16(tree->right);
    }
    return;
}

void print_path_for_given_sum(struct node *root,int sum,int *path,int path_len)
{
    if(!root)
        return;

    path[path_len]=root->data;
    sum-=root->data;
    if(sum==0)
    {
        printf("Paths is\n");
        for(int i=0;i<=path_len;i++)
            printf("%d\t",path[i]);
        printf("\n");
    }
    else
    {
        print_path_for_given_sum(root->left,sum,path,path_len+1);
        print_path_for_given_sum(root->right,sum,path,path_len+1);
    }
}

int test_main16()
{
    int n=11;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        if(i==4)
            {insert_to_tree16(&tree_head,12*10);continue;}
        insert_to_tree16(&tree_head,(i+1)*10);
    }
    printf("IN-ORDER\t\t");
    inorder16(tree_head);
    printf("\n");

    int sum=150;
    int path[100];
    int path_len=0;
    print_path_for_given_sum(tree_head,sum,path,path_len);

    return 0;
}
