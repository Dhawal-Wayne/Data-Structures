#include "bst.hpp"

struct node *find_max5(struct node *root)
{
    if(root)
    {
        while(root)
        {
            if(root->right)
                root=root->right;
            else
                break;
        }
        return root;
    }
    else
        return NULL;
}

struct node *find_min5(struct node *root)
{
    if(root)
    {
        while(root)
        {
            if(root->left)
                root=root->left;
            else
                break;
        }
        return root;
    }
    return NULL;
}

int inorder_successor5(struct node *root)
{
    if(root)
    {
        struct node *next=find_min5(root->right);
        if(next)
            return next->data;
        else
            return root->data;
    }
    return -1;
}

int inorder_predecessor5(struct node *root)
{
    if(root)
    {
        struct node *prev=find_max5(root->left);
        if(prev)
            return prev->data;
        else
            return root->data;
    }
    return -1;
}

int test_main5()
{
    struct node *tree_head=NULL;
    int n=10;
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    for(int i=0;i<n;i++)
    {
        insert_to_tree(&tree_head,arr[i]);
    }

    int inorder_pre=0,inorder_suc=0;

    inorder_pre=inorder_predecessor5(tree_head);
    inorder_suc=inorder_successor5(tree_head);

    printf("Predecessor-->%d\tSuccessor-->%d\n",inorder_pre,inorder_suc);
    return 0;
}
