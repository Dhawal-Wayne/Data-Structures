#ifndef BST_HPP_INCLUDED
#define BST_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//int arr[]={20,10,30,5,11,25,32,66,15,41};

extern struct node * create_node(int data);

extern void insert_to_tree(struct node **root,int data);

extern void inorder(struct node * root);

extern void preorder(struct node *root);

extern void postorder(struct node *root);

#endif // BST_HPP_INCLUDED
