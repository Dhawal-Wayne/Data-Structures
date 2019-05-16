
#include "bst.hpp"
//Given an complete binary tree we need to print sorted order
//root,2*root+1,2*root+2-->root,left,right

void print_sorted_complete_bin_tree(int arr[],int start,int end)
{
    if(start < end)
    {
        print_sorted_complete_bin_tree(arr,start*2+1,end);
        printf("%d\t",arr[start]);
        print_sorted_complete_bin_tree(arr,start*2+2,end);
    }
}
int test_main6()
{
    int arr[] = {4, 2, 5, 1, 3};
    printf("Sorted Order\n");
    print_sorted_complete_bin_tree(arr,0,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
