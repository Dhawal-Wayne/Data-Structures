#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int test_main4()
{
    int arr[]={1,0,1,1,2,3,4,5,5,5,4,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original Arrays is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    int top_of_stack=1;

    for(int i=0;i<n;i++)
    {
        if(i+1<n)
        {
            if(arr[i]==arr[i+1]);
            else
            {
                arr[top_of_stack]=arr[i+1];
                top_of_stack++;
            }
        }
    }
    printf("Altered Array is\n");
    for(int i=0;i<top_of_stack;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
