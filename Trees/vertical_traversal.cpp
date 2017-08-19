#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node * create_node22(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree22(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node22(data);
    }
    else
    {
        queue <struct node *> queue_1;

        queue_1.push(*root);
        while(!queue_1.empty())
        {
            struct node *temp=queue_1.front();
            queue_1.pop();
            if(temp->left)
                queue_1.push(temp->left);
            else
            {
                temp->left=create_node22(data);
                break;
            }
            if(temp->right)
            {
                queue_1.push(temp->right);
            }
            else
            {
                temp->right=create_node22(data);
                break;
            }
        }
    }
    return ;
}

void vertical_traversal(struct node *root,map<int,vector<int> > &vertical_hash,int index)
{
    if(root)
    {
        vertical_hash[index].push_back(root->data);
        vertical_traversal(root->left,vertical_hash,index-1);
        vertical_traversal(root->right,vertical_hash,index+1);
    }
    return;
}

int test_main22()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree22(&tree_head,(i+1)*10);

    map<int,vector<int> > vertical_wise_order;
    vertical_traversal(tree_head,vertical_wise_order,0);

    map<int,vector<int> >::iterator i;
    printf("No of levels %d",vertical_wise_order.size());
    int level=0;
    for(i=vertical_wise_order.begin();i!=vertical_wise_order.end();i++,level++)
    {
        printf("\n%d==>\t",level+1);
        for(int j=0;j<i->second.size();j++)
            printf("%d\t",i->second[j]);
    }
    return 0;
}
