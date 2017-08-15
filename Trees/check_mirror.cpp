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

struct node *create_node18(int data)
{
    struct node * new_node=NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree18(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node18(data);
    }
    else
    {
        queue<struct node *> my_queue;
        my_queue.push(*root);
        while(!my_queue.empty())
        {
            struct node *temp=my_queue.front();
            my_queue.pop();
            if(temp->left)
                my_queue.push(temp->left);
            else
            {
                temp->left=create_node18(data);
                break;
            }
            if(temp->right)
            {
                my_queue.push(temp->right);
            }
            else
            {
                temp->right=create_node18(data);
                break;
            }
        }
    }
    return;
}

void inorder18(struct node *root)
{
    if(root)
    {
        inorder18(root->left);
        printf("%d\t",root->data);
        inorder18(root->right);
    }
    return;
}

struct node * make_mirror18(struct node *root_1)
{
    if(root_1)
    {
        struct node *new_node=NULL;
        new_node=create_node18(root_1->data);
        new_node->left=make_mirror18(root_1->right);
        new_node->right=make_mirror18(root_1->left);
        return new_node;
    }
}

int is_mirror_image(struct node *root_1,struct node *root_2)
{
    if(!root_1 && !root_2)
        return 1;
    if(!root_1 || !root_2)
        return 0;
     return (root_1->data== root_2->data) && is_mirror_image(root_1->left,root_2->right) && is_mirror_image(root_1->right,root_2->left);
}

int test_main18()
{
    struct node *tree_head=NULL;
    int n=10;
    for(int i=1;i<=n;i++)
    {
        insert_to_tree18(&tree_head,i*10);
    }

    printf("INORDER\t\t\t");
    inorder18(tree_head);
    printf("\n");

    struct node *mirror_tree_head=make_mirror18(tree_head);

    printf("INORDER\t\t\t");
    inorder18(mirror_tree_head);
    printf("\n");

    printf("IS MIRROR?! %d\n",is_mirror_image(tree_head,mirror_tree_head));
    printf("IS MIRROR?! %d\n",is_mirror_image(tree_head,tree_head));
    printf("IS MIRROR?! %d\n",is_mirror_image(mirror_tree_head,mirror_tree_head));

    return 0;
}
