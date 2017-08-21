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

struct node * create_node24(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree24(struct node **root,int data)
{
    if(!(*root))
        *root=create_node24(data);
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
                temp->left=create_node24(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node24(data);
                break;
            }
        }
    }
    return ;
}

struct node *lca(struct node *root,int child1,int child2)
{
    if(root)
    {
        if(root->data==child1 || root->data==child2)
        {
            return root;
        }

        //Algo is such that if one is in left sub tree and other in right
        //both being present either side hence the one we are in must be LCA
        //if left is not null but right return null it implies that
        //LCA is in left sub tree vice-versa

        struct node *present_in_left=lca(root->left,child1,child2);
        struct node *present_in_right=lca(root->right,child1,child2);

        if(present_in_left && present_in_right)
            return root;
        else
            return (present_in_left)?present_in_left:present_in_right;
    }
    else
        return NULL;
}

int test_main24()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree24(&tree_head,(i+1)*10);

    int child1=30,child2=70;
    struct node *_lca=lca(tree_head,child1,child2);
    if(_lca!=NULL)
        printf("LCA of %d and %d is %d\n",child1,child2,_lca->data);
    else
        printf("GIVEN DATA DOESNOT EXIST\n");
    return 0;
}
