#include "bst.hpp"
#include <climits>

void floorUtil(struct node *root,int data,int *floor_of_data)
{
    if(root)
    {
        floorUtil(root->left,data,floor_of_data);
        if(*floor_of_data<root->data && root->data<data)
            *floor_of_data=root->data;
        floorUtil(root->right,data,floor_of_data);
    }
}

int floor(struct node *root,int data)
{
    int floor_of_data=INT_MIN;
    floorUtil(root,data,&floor_of_data);
    return floor_of_data;
}

void ceilUtil(struct node *root,int data,int *ceil_of_data)
{
    if(root)
    {
        ceilUtil(root->left,data,ceil_of_data);
        if(*ceil_of_data>root->data && root->data > data)
            *ceil_of_data=root->data;
        ceilUtil(root->right,data,ceil_of_data);
    }
}

int ceil(struct node *root,int data)
{
    int ceil_of_data=INT_MAX;
    ceilUtil(root,data,&ceil_of_data);
    return ceil_of_data;
}

int test_main9()
{
    int n=10;
    struct node *tree_head=NULL;
    int arr[]={20,10,30,5,11,25,32,66,15,41};
    for(int i=0;i<n;i++)
        insert_to_tree(&tree_head,arr[i]);

    printf("Inorder\t\t\t");
    inorder(tree_head);
    printf("\n");

    int floor_data=arr[rand()%10],ceil_data=arr[(rand()%10+rand()%10)%10];
    printf("Floor of %d is %d\n",floor_data,floor(tree_head,floor_data));
    printf("Ceil of %d is %d\n",ceil_data,ceil(tree_head,ceil_data));

    return 0;
}
