/*
AVL trees are height balanced binary trees.
Height difference between heights of left and right subtrees for every node is less than or equal to 1.
Balanced factor = Height of right subtree- Height of left sutree
Can be -1,0 or 1 for a node to be balanced in a Binary search tree
Can be -1,0,1 for all nodes of an AVL tree

In order to balance an AVL tree after insertion, we can follow the following rules:
1. For a Left-Left Insertion- Right rotate once wrt the first imbalanced node
2.For a Right-Right Insertion-Left rotate once wrt the first imbalanced node
3.For a Left-Right Insertion- Left rotate once and then Right rotate once
4.For a Right-Left Insertion- Right rotate once and then Left rotate once

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
    int height;
}node;

void preorder(node * n){
//    printf("code came here!\n");
    if(n!=NULL)
    {
        printf("%d,",n->data);
        preorder(n->left);
        preorder(n->right);
    }
    
}
int max(int a ,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int getheight(node * ptr)
{
    if(ptr==NULL)
        return 0;
    return ptr->height; //this fuction is needed to handle to NULL case.
}

node * createnode(int data)
{
    node *p;//constructing the  node
    p = (node*)malloc(sizeof(node));//allocating memory in heap
    p->data = data;//setting the data
    p->left = NULL;//setting its pointers to NULL
    p->right = NULL;
    p->height = 1;
    return p;//returning the node
}
int getbalancefactor(node * n)
{
    if(n==NULL)
        return 0;
    return getheight(n->left) - getheight(n->right);
}

node * rightrotation(node * imbalanced)
{
    node * tmp = imbalanced->left;
    imbalanced->left = tmp->right;
    tmp->right = imbalanced;
    //updating heights
    // tmp->height +=1;
    // imbalanced->height -=1;
    tmp->height = max(getheight(tmp->left),getheight(tmp->right)) +1; //height allocation based on children nodes
    imbalanced->height = max(getheight(imbalanced->left),getheight(imbalanced->right)) +1;
    //as the height of the children nodes remain constant it would be better to use their heights 
    
    return tmp;

    

}
node * leftrotation(node * imbalanced)
{
    node * tmp = imbalanced->right;
    imbalanced->right = tmp->left;
    tmp->left = imbalanced;

    // tmp->height +=1;
    // imbalanced->height -=1;

    tmp->height = max(getheight(tmp->left),getheight(tmp->right)) +1; //height allocation based on children nodes
    imbalanced->height = max(getheight(imbalanced->left),getheight(imbalanced->right)) +1;
    //as the height of the children nodes remain constant it would be better to use their heights
    return tmp;
    

}

// int  insertintoavl(node * n, int element)
// {
//     node *tmp = createnode(element);
//     node * prev = n;
//     while(n!=NULL)
//     {   prev = n;
//         if(n->data== element)
//         {
//             printf("Cannot insert. %d already in BST\n",element);
//             return -1;
//         }
//         else if (n->data>element)
//             n = n->left;
//         else
//             n = n->right;
//     }
//     if(prev->data<element)
//     {
//         prev->right = tmp;
//     }
//     else
//     {
//         prev->left = tmp;
//     }
//     return 0;

// }
node * insert(node * node, int key)
{
    if(node ==NULL)
     return (createnode(key));

     if(key < node->data)
     {
        node->left = insert(node->left,key);
     }
     else if(key>node->data)
     {
        node->right = insert(node->right,key);
     }
     

     //updating heights from leaf nodes
     node->height = 1+ max(getheight(node->left),getheight(node->right));
     int bf = getbalancefactor(node);

     //left left case
     if(bf>1 && key<node->left->data)
     {
        return rightrotation(node);
     }
     //right right case
     if(bf<-1 && key>node->right->data)
     {
        return leftrotation(node);
     }
     //left right case
     if(bf>1 && key>node->left->data)
     {  
        node->left =  leftrotation(node->left);
        return rightrotation(node);
     }
     //right left case
     if(bf<-1 && key<node->right->data)
     {  
        node->right = rightrotation(node->right);
        return rightrotation(node);
     }

     return node;
}
int main()
{
    node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    preorder(root);
    return 0;
}
