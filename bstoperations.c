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

node * searchinbst(node * root,int key)
{   static int funccall = 0;
    funccall+=1;
    printf("%d\n",funccall);
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    if(root->data>key)
        return searchinbst(root->left,key);
    else
        return searchinbst(root->right,key);

}

node * searchiterative(node * root,int key)
{
    node * n = root;
    while(n!=NULL)
    {
        if(n->data== key)
            return n;
        else if (n->data>key)
            n = n->left;
        else
            n = n->right;
    }
    return n;
}

int  insertintobst(node * n, int element)
{
    node *tmp = createnode(element);
    node * prev = n;
    while(n!=NULL)
    {   prev = n;
        if(n->data== element)
        {
            printf("Cannot insert. %d already in BST\n",element);
            return -1;
        }
        else if (n->data>element)
            n = n->left;
        else
            n = n->right;
    }
    if(prev->data<element)
    {
        prev->right = tmp;
    }
    else
    {
        prev->left = tmp;
    }
    return 0;

}
node * inorderpredecessor(node * root)
{
    //inorderpredecessor is the rightmost child of left node of the root node
    node * n = root->left;
    while(n->right != NULL)
    {
        n = n->right;
    }
    return n;
}

node * deletenode(node * root,int value)
{
    //checking if the root node is not null
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == value)
            free(root);
        else
            printf("Element %d not found  in BST\n",value);
        return NULL;
    }

    
    //searching for the node to be deleted
    if(value<root->data)
        root->left = deletenode(root->left,value);
    else if(value>root->data)
        root->right = deletenode(root->right,value);
    else
    {//value is in root node   
        node * ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left,ipre->data);

    }
    return root;
}



int main()
{
    node *p = createnode(50);
    node *p1= createnode(31);
    node *p2 = createnode(65);
    node *p3 = createnode(25);
    node *p4 = createnode(45);
    node *p5 = createnode(56);
    node *p6= createnode(70);
    node *p7 = createnode(27);
    node *p8 = createnode(60);
    node *p9 = createnode(67);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p3->right = p7;
    p6->left = p9;
    p5->right = p8;
    // struct node * n = searchinbst(p,7034);
    // if(n != NULL)
    //     printf("%i\n",n->data);
    // else
    //     printf("Not found\n");

    
    // struct node * a = searchiterative(p,65);
    // if(a!= NULL)
    //     printf("%i\n",a->data);
    // else
    //     printf("Not found\n");

    // inordertraversal(p);
    // printf("\n");
    // insertintobst(p,23);
    //     inordertraversal(p);
    // printf("\n");
    // insertintobst(p,45);
    //     inordertraversal(p);
    // printf("\n");
    // insertintobst(p,65);
    // insertintobst(p,438);
    // insertintobst(p,66);
    //     inordertraversal(p);
    // printf("\n");

    inordertraversal(p);
    printf("\n");
    deletenode(p,45);
    inordertraversal(p);
    printf("\n");
    deletenode(p,70);
    inordertraversal(p);
    printf("\n");
    deletenode(p,57);
    inordertraversal(p);
    printf("\n");
    deletenode(p,50);
    inordertraversal(p);
    printf("\n");
    printf("root: %d\n",p->data);

}
