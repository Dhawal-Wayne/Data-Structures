#include "bst.hpp"
#include <queue>

using namespace std;

void print_keys_between(struct node *root,int k1,int k2)
{
    if(root)
    {
        queue<struct node *> my_queue;
        my_queue.push(root);
        while(!my_queue.empty())
        {
            struct node *temp=NULL;
            temp=my_queue.front();
            my_queue.pop();
            if(temp->data > k1 && temp->data < k2)
                printf("%d\t",temp->data);
            if(temp->left)
                my_queue.push(temp->left);
            if(temp->right)
                my_queue.push(temp->right);
        }
    }
}

int test_main10()
{
    struct node *tree_head=NULL;
    int n=10;
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,arr[i]);

    printf("Inorder\t\t\t");
    inorder(tree_head);
    printf("\n");

    int k1=0,k2=0;
    printf("Enter K1 K2\t");
    scanf("%d%d",&k1,&k2);
    print_keys_between(tree_head,k1,k2);
    return 0;
}
