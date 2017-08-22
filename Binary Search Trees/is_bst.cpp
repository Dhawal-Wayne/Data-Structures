#include "bst.hpp"
#include <climits>

int is_bst(struct node *root,int *prev)
{
    if(root)
    {
        // SIMPLE A INORDER CHECK
        if(!is_bst(root->left,prev))
            return 0;
        if(root->data<*prev)
            return 0;
        else
            *prev=root->data;
        return is_bst(root->right,prev);
    }
    return 1;
}

int test_main4()
{
    struct node *tree_head=NULL;
    int n=10;
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    for(int i=0;i<n;i++)
    {
        insert_to_tree(&tree_head,arr[i]);
    }

    printf("INORDER\t\t\t");
    inorder(tree_head);
    printf("\n");

    printf("PREORDER\t\t\t");
    preorder(tree_head);
    printf("\n");

    int min_val=INT_MIN;
    printf("IS BST ? %d\n",is_bst(tree_head,&min_val));

    swap(tree_head->left,tree_head->right);

    printf("IS BST ? %d\n",is_bst(tree_head,&min_val));

    return 0;
}
