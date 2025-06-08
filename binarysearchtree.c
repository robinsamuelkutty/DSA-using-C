/*
1.it is a type of Binary tree!

properties
1. all node of the left subtree are lesser.
2.all nodes of the right subtree are greater.
3.left and right subtrees are also binary search tree
4.There are no duplicate nodes.
5. Inorder traversal of the binary search tree gives an ascending sorted array.(very imp.)(using this property
we confirm that a BT is a BST.)
*/



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

void inordertraversal(node * n){
//    printf("code came here!\n");
    if(n!=NULL)
    {
    
        inordertraversal(n->left);
        printf("%d,",n->data);
        inordertraversal(n->right);
    }
    
}
int isbst(node * n)
{   
    static struct node * prev = NULL;
    if(n!=NULL)
    {
        
        if(!isbst(n->left))
        {
            return 0;
        }
        else if(prev!=NULL && n->data<=prev->data)
        {
            return 0;
        }
        prev = n;
        return isbst(n->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    node *p = createnode(7);
    node *p1= createnode(2);
    node *p2 = createnode(8);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->right = p4;
    // printf("%d,%d,%d",p->data,p->left->data,p->right->data);

    printf("%d\n",isbst(p));
}
