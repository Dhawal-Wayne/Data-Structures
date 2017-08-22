#include "bst.hpp"



int lsa3(struct node *root,int child1,int child2)
{
    if(root)
    {
        while(root)
        {
            if(root->data > child1 && root->data > child2)
            {
                root=root->left;
            }
            else if(root->data < child1 && root->data > child2)
            {
                root=root->right;
            }
            else
                break;
        }
        return root->data;
    }
    else
        return -1;
}


int test_main3()
{
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,arr[i]);

    int child1=arr[6],child2=arr[3];
    int _lsa=lsa3(tree_head,child1,child2);
    if(_lsa!=-1)
        printf("LSA OF %d %d is %d\n",child1,child2,_lsa);
    else
        printf("LSA DONOT EXISTS\n");
    return 0;
}
