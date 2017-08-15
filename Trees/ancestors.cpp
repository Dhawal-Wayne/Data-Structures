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

struct node * create_node20(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree20(struct node **root,int data)
{
if(!(*root))
        *root=create_node20(data);
    else
    {
        queue<struct node*> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=NULL;
            temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
            {
                my_queue.push(temp->left);
            }
            else
            {
                temp->left=create_node20(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node20(data);
                break;
            }
        }
    }
    return;
}
//Base Case is node data must be equal to the given data
//Hence traverse till there mean while print the node in between
//hence base would be root->left->data==given_data or root->right->data=given data else traverse to
//right or left of node
bool find_ancestors(int data,struct node *root)
{
    if(!root)
        return false;
    if((root->left && root->left->data==data)||(root->right && root->right->data==data)||find_ancestors(data,root->left)||find_ancestors(data,root->right))
    {
        printf("%d\t",root->data);
        return 1;
    }
    else
        return 0;
}


void inorder20(struct node *root)
{
    if(root)
    {
        inorder20(root->left);
        printf("%d\t",root->data);
        inorder20(root->right);
    }
}

int test_main20()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree20(&tree_head,(i+1)*10);

    printf("IN-ORDER IS \t\t\t");
    inorder20(tree_head);
    printf("\n");

    int data=90;
    printf("Ancestors of %d are\n",data);

    find_ancestors(data,tree_head);
    return 0;
}
