#include "bst.hpp"

int test_main1()
{
    int n=10;
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,arr[i]);

    printf("IN-ORDER\t\t\t");
    inorder(tree_head);
    printf("\n");

    printf("POST ORDER\t\t\t");
    postorder(tree_head);
    printf("\n");

    printf("PRE ORDER\t\t\t");
    preorder(tree_head);
    printf("\n");

    return 0;
}
