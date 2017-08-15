#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node * create_node13(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->right=NULL;
    new_node->left=NULL;

    return new_node;
}

void insert_to_tree13(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node13(data);
    }
    else
    {
        queue <struct node *> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
            {
                my_queue.push(temp->left);
            }
            else
            {
                temp->left=create_node13(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node13(data);
                break;
            }
        }
    }
    return;
}

int* max_sum_level(struct node *root)
{
    int *result=NULL;
    if(root)
    {
        queue<struct node *> my_queue_1,my_queue_2;
        my_queue_1.push(root);
        int current_sum=0,max_sum=root->data;
        int current_level=0,result_level=0;
        while(!my_queue_1.empty())
        {
            struct node *temp=my_queue_1.front();
            my_queue_1.pop();
            current_sum+=temp->data;
            if(temp->left)
            {
                my_queue_2.push(temp->left);
            }
            if(temp->right)
            {
                my_queue_2.push(temp->right);
            }
            if(my_queue_1.empty())
            {
                current_level++;
                if(current_sum>max_sum)
                {
                    max_sum=current_sum;
                    result_level=current_level;
                }
                swap(my_queue_1,my_queue_2);
                current_sum=0;
            }
        }
        result=(int *)calloc(2,sizeof(int));
        result[0]=max_sum,result[1]=result_level;
    }
    return result;
}

void inorder13(struct node *root)
{
    if(root)
    {
        inorder13(root->left);
        printf("%d\t",root->data);
        inorder13(root->right);
    }

}

int test_main13()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=0;i<n;i++)
    {
        insert_to_tree13(&tree_head,i);
    }
    printf("Inorder\t\t\t");
    inorder13(tree_head);
    printf("\n");

    int *result=max_sum_level(tree_head);
    printf("DATA %d\t%d\n",result[0],result[1]);

    return 0;
}
