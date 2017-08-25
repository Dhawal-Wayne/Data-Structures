#include <stdio.h>
#include <stdlib.h>
void print_preorder(int *arr,int low,int high)
{
    if(low<=high)
    {
    printf("%d ",arr[(low+high)/2]);
    print_preorder(arr,low,(low+high)/2-1);
    print_preorder(arr,(low+high)/2+1,high);
    }
}

int test_main8() {
	//code
	int tests=0;
	scanf("%d",&tests);
	while(tests)
	{
	    int size=0;
	    int *arr=NULL;

	    scanf("%d",&size);
	    arr=(int *)calloc(size,sizeof(int));

	    for(int i=0;i<size;i++)
	    {
	        scanf("%d",&arr[i]);
	    }

	    print_preorder(arr,0,size-1);
	    printf("\n");

	    tests--;
	}
	return 0;
}
