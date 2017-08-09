#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue_node
{
    struct node *data;
    struct queue_node *next;
};

void enqueue11(struct queue_node **queue,struct node *data)
{
    struct queue_node *new_node=NULL;
    new_node=(struct queue_node*)calloc(1,sizeof(struct queue_node));
    new_node->data=data;
    new_node->next=*queue;
    *queue=new_node;

    return;
}

struct node * dequeue11(struct queue_node **queue)
{
    struct queue_node *result=NULL;
    if(*queue)
    {
        result=*queue;
        *queue=(*queue)->next;
        result->next=NULL;
        return result->data;
    }
    return NULL;
}

struct node * create_node11(int data)
{
    struct node * new_node = NULL;
    new_node=(struct node *)calloc(1,sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void insert_to_tree11(struct node **root,int data)
{
    if(!(*root))
    {
        *root=create_node11(data);
    }
    else
    {
        struct queue_node *my_queue=NULL;
        enqueue11(&my_queue,*root);
        while(my_queue)
        {
            struct node * temp=dequeue11(&my_queue);
            if(temp->left)
            {
                enqueue11(&my_queue,temp->left);
            }
            else
            {
                temp->left=create_node11(data);
                break;
            }
            if(temp->right)
            {
                enqueue11(&my_queue,temp->right);
            }
            else
            {
                temp->right=create_node11(data);
                break;
            }
        }
    }
    return;
}

void inorder11(struct node *root)
{
    if(root)
    {
        inorder11(root->left);
        printf("%d\t",root->data);
        inorder11(root->right);
    }
    return;
}

int height_of_bin_tree11(struct node *root)
{
    if(!root)
        return 0;
    else
    {
        int left_height=height_of_bin_tree11(root->left);
        int right_height=height_of_bin_tree11(root->right);

        return left_height>right_height?left_height+1:right_height+1;
    }
}

//Its is Simple Problem but its complicated by the intuition of people
//Just think what is diameter of be when flatten it just the
//height of tree in both side but the tricky part is tree_head need not pass through it
//hence we device an algo as follows

int diameter_of_tree(struct node *root)
{
    if(root)
    {
        int left_diameter=diameter_of_tree(root->left);
        int right_diameter=diameter_of_tree(root->right);

        //When spread height of both side becomes diameter ..

        int height=height_of_bin_tree11(root->left)+height_of_bin_tree11(root->right)+1;
        int diameter=left_diameter>right_diameter?left_diameter:right_diameter;

        return height>diameter?height:diameter;
    }
    return 0;
}

int main()
{
    int n=10;
    struct node *tree_head=NULL;
    for(int i=0;i<n;i++)
    {
        insert_to_tree11(&tree_head,i*10+rand()%100);
    }

    printf("In-order \t\t\t");
    inorder11(tree_head);
    printf("\n");

    printf("Diameter of Tree \t%d\n",diameter_of_tree(tree_head));

    return 0;
}
