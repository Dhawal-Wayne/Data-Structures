
#include "bst.hpp"

struct node *lca3(struct node *root,int child_1,int child_2)
{
    if(root)
    {
        if((root->data>=child_1 && root->data<=child_2)||(root->data<=child_1 && root->data>=child_2))
            return root;
        else if(root->data<child_1 && root->data < child_2)
            return lca3(root->right,child_1,child_2);
        else
            return lca3(root->left,child_1,child_2);
    }
    else
        return NULL;
}

int test_main3()
{
    int n=10;
    struct node *tree_head=NULL;
    int arr[]={32,56,3,57,23,44,66,83,19,10};
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,arr[i]);

    printf("Inorder\n");
    inorder(tree_head);
    printf("\n");

    int child_1=arr[rand()%10],child_2=arr[rand()%10];

    struct node *_lca=lca3(tree_head,child_1,child_2);
    if(_lca)
    printf("%d is LCA of %d %d\n",_lca->data);
    else
    printf("NO LCA\n");
    return 0;
}
