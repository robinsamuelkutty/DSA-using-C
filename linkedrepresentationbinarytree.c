#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

node * createnode(int data)
{
    node *p;//constructing the  node
    p = (node*)malloc(sizeof(node));//allocating memory in heap
    p->data = data;//setting the data
    p->left = NULL;//setting its pointers to NULL
    p->right = NULL;
    return p;//returning the node
}


int main(void)
{
    // node *p;//constructing the root node
    // p = (node*)malloc(sizeof(node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;
    
    // node *p1;//constructing the second node
    // p1 = (node*)malloc(sizeof(node));
    // p->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;

    // node *p2;//constructing the third node
    // p2 = (node*)malloc(sizeof(node));
    // p->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    // p->left = p1;//linking the root node to the left and right nodes.
    // p->right = p2;

    //creating the node using functions.
    node *p = createnode(2);
    node *p1= createnode(1);
    node *p2 = createnode(4);
    p->left = p1;
    p->right = p2;

}

