/*
preorder traversal = root->left subtree -> right subtree
postorder traversal = left subtree -> right subtree ->root
inorder traversal = left subtree ->root ->right subtree
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
//n is root
void preordertraversal(node * n){
//    printf("code came here!\n");
    if(n!=NULL)
    {
        printf("%d,",n->data);
        preordertraversal(n->left);
        preordertraversal(n->right);
    }
    
}

void postordertraversal(node * n){
//    printf("code came here!\n");
    if(n!=NULL)
    {
        
        postordertraversal(n->left);
        postordertraversal(n->right);
        printf("%d,",n->data);
    }
    
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
int main()
{
    node *p = createnode(7);
    node *p1= createnode(2);
    node *p2 = createnode(3);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->right = p4;
    // printf("%d,%d,%d",p->data,p->left->data,p->right->data);

    preordertraversal(p);
    printf("\n");
    postordertraversal(p);
    printf("\n");
    inordertraversal(p);
    printf("\n");
}
/* 
trick to find inorder,preorder and postorder traversal
refer to notes for images (video 70 cwh dsa)

preorder- 
draw small lines from left side of all nodes and then think that you are driving a road along left side from the
root. write all the elements in output when the car intersects with the small lines drawn.

postorder-
draw small lines on right side of all nodes --""--- same as above--""--

inorder-
draw small lines on below side of all nodes ---------same as above--------------


*/