#ifndef BST_HPP_INCLUDED
#define BST_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

extern struct node * create_node(int data);

extern void insert_to_tree(struct node **root,int data);

extern void inorder(struct node * root);

extern void preorder(struct node *root);

extern void postorder(struct node *root);

#endif // BST_HPP_INCLUDED
