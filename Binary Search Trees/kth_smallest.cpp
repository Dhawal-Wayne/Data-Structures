#include "bst.hpp"

void kth_smallest(struct node *root,int *k,int *kth_smallest_node)
{
    if(root && *k>0)
    {

        kth_smallest(root->left,k,kth_smallest_node);
        if(*k>0)
        {
            *kth_smallest_node=root->data;
            *k-=1;
        }
        if(*k>0)
        {
            kth_smallest(root->right,k,kth_smallest_node);
        }
    }

}

int test_main7()
{
    int n=10;
    int arr[]={20,10,30,5,11,25,32,66,15,41};

    struct node *tree_head=NULL;

    for(int i=0;i<n;i++)
    {
        insert_to_tree(&tree_head,arr[i]);
    }

    printf("Tree is \n");
    inorder(tree_head);
    printf("\n");

    int k=11;
    int k2=k;
    int kth_smallest_node_data=0;
    kth_smallest(tree_head,&k2,&kth_smallest_node_data);

    printf("%d is %d th smallest of tree\n",kth_smallest_node_data,k);

    return 0;
}
