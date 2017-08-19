#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node23(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree23(struct node **root,int data)
{
    if(!(*root))
        *root=create_node23(data);
    else
    {
        queue<struct node*> queue_1;
        queue_1.push(*root);
        while(!queue_1.empty())
        {
            struct node *temp=queue_1.front();
            queue_1.pop();
            if(temp->left)
                queue_1.push(temp->left);
            else
            {
                temp->left=create_node23(data);
                break;
            }
            if(temp->right)
                queue_1.push(temp->right);
            else
            {
                temp->right=create_node23(data);
                break;
            }
        }
    }
    return;
}

void vertical_sum(struct node *root,map<const int,int> &vertical_hash,int index)
{
    if(root)
    {
        vertical_hash[index]=root->data;
        vertical_sum(root->left,vertical_hash,index-1);
        vertical_sum(root->right,vertical_hash,index+1);
    }
}

int test_main23()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
        insert_to_tree23(&tree_head,(i+1)*10);
    printf("Vertical wise sum\n");

    map<const int,int> vertical_hash;
    vertical_sum(tree_head,vertical_hash,0);

    map<const int,int>::iterator i;

    int no_of_levels=vertical_hash.size();

    printf("No of levels %d\n",no_of_levels);

    for(i=vertical_hash.begin();i!=vertical_hash.end();i++)
    {
        printf("level sum %d==>%d\n",i->first+no_of_levels/2+1,i->second);
    }

    return 0;
}
