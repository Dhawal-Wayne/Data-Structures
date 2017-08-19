#include <stdlib.h>
#include <stdio.h>
#include "bst.hpp"

int test_main1()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,(rand()%100+1)*10);

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
