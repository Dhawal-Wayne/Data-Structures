#include "bst.hpp"
#include <stdio.h>
#include <stdlib.h>

int min_of_tree2(struct node *root)
{
    if(root)
    {
        if(root->left)
            return min_of_tree1(root->left);

        return root->data;
    }
    return -1;
}

int max_of_tree2(struct node *root)
{
    if(root)
    {
        if(root->right)
            return max_of_tree1(root->right);

        return root->data;
    }
    return -1;
}

int test_main2()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,rand()%100+10);

    printf("Inorder\t\t\t");
    inorder(tree_head);
    printf("\n");

    printf("Max of Tree is %d\n",max_of_tree2(tree_head));
    printf("Min of Tree is %d\n",min_of_tree2(tree_head));

    return 0;
}
