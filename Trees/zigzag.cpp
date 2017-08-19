#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create_node19(int data)
{
    struct node *new_node=NULL;
    new_node=(struct node*)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree19(struct node **root,int data)
{
    if(!(*root))
        *root=create_node19(data);
    else
    {
        queue<struct node*> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=NULL;
            temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
            {
                my_queue.push(temp->left);
            }
            else
            {
                temp->left=create_node19(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node19(data);
                break;
            }
        }
    }
    return;
}

void print_zigzag(struct node *root)
{
    if(root)
    {
        //Instead of using queues uses stacks and find the result
        //Push to stack2 while stack1 not empty
        //Push to stack1 while stack2 not empty
        //Continue two stacks are empty
        stack<struct node *> stack_1,stack_2;
        stack_1.push(root);
        while(!stack_1.empty() || !stack_2.empty())
        {
            while(!stack_1.empty())
            {
                struct node *temp=NULL;
                temp=stack_1.top();

                printf("%d\t",temp->data);

                stack_1.pop();
                if(temp->left)
                    stack_2.push(temp->left);
                if(temp->right)
                    stack_2.push(temp->right);
            }
            while(!stack_2.empty())
            {
                struct node *temp=NULL;
                temp=stack_2.top();

                printf("%d\t",temp->data);

                stack_2.pop();
                if(temp->right)
                    stack_1.push(temp->right);
                if(temp->left)
                    stack_1.push(temp->left);
            }
        }
    }
    return;
}

int test_main19()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree19(&tree_head,(i+1)*10);
    }
    printf("ZIG-ZAG TREE\n");
    print_zigzag(tree_head);
	return 0;
}
