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

struct node * create_node21(int data)
{
    struct node *new_node = NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node ));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=data;

    return new_node;
}

void insert_to_tree21(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node21(data);
    }
    else
    {
        queue<struct node*> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
                my_queue.push(temp->left);
            else
            {
                temp->left=create_node21(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node21(data);
                break;
            }
        }
    }
    return;
}

int print_previous_ancestor(struct node *root,int data)
{
    if(!root)
        return 0;
    else
    {
        if((root->left && root->left->data==data)||(root->right && root->right->data==data))
        {
            printf("%d\t",root->data);
            return 1;
        }
        else if(print_previous_ancestor(root->left,data) || print_previous_ancestor(root->right,data))
        {
            return 0;
        }
        else
            return 0;
    }
}
void inorder21(struct node *root)
{
    if(root)
    {
        inorder21(root->left);
        printf("%d\t",root->data);
        inorder21(root->right);
    }
}
int tree_main21()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)

        insert_to_tree21(&tree_head,(i+1)*10);
    printf("INORDER\t");
    inorder21(tree_head);
    printf("\n");

    printf("PREVIOUS ANCESTOR IS\n");
    int child=100;
    print_previous_ancestor(tree_head,child);
    return 0;
}
