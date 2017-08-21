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

struct node * create_node26(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree26(struct node **root,int data)
{
    if(!(*root))
        *root=create_node26(data);
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
                temp->left=create_node26(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node26(data);
                break;
            }
        }
    }
    return ;
}


//Similar to is ISOTHERMIC
//CAN BE SEEN MORE CLEARLY IF USE BST INSTEAD OF BT
int is_quasi_ismorphic(struct node *root_1,struct node *root_2)
{
    if(root_1 && root_2)
    {
        if((is_quasi_ismorphic(root_1->left,root_2->left) && is_quasi_ismorphic(root_1->right,root_2->right))||
           (is_quasi_ismorphic(root_1->left,root_2->right)&&is_quasi_ismorphic(root_1->right,root_2->left)))
            return 1;
        else
            return 0;
    }
    else if(!root_1 && !root_2)
        return 1;
    else
        return 0;
}


int test_main26()
{
    int n=10;
    struct node *tree_head_1=NULL,*tree_head_2=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree26(&tree_head_1,rand()%1000);
        insert_to_tree26(&tree_head_2,rand()%1000);
    }


    struct node *temp=tree_head_1->left;
    tree_head_1->left=tree_head_1->right;
    tree_head_1->right=temp;

    printf( "IS Quasi-ISOMORPHIC %d\n",is_quasi_ismorphic(tree_head_1,tree_head_2));

    return 0;
}

