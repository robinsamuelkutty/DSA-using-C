#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node * next;
}Node;
void linkedlisttraversal(Node * ptr)
{   //use do while loop
    Node * i= ptr;
    // for(i = ptr; i->next!= ptr; i=i->next)
    // {
    //     printf("%d ",i->data);
    // }
    // printf("%d ",i->data);
    
    do
    {
        printf("%d ",i->data);
        i = i->next;
    }while(i!= ptr);
    printf("\n");
}
Node * insertathead(Node * ptr, Node * insertnode)
{
    Node * i= ptr;
    while(i->next != ptr)
    {
        i = i->next;
    }
    insertnode->next = ptr;
    i->next = insertnode;
    ptr = insertnode;
    return ptr;

}

int main(void)
{
    Node * head;
    Node * second;
    Node * third;
    Node * fourth;
    //allocate memory for linked list in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    

    //assigning values
    //linking first and second node 
    head->data = 7;
    head->next = second;
    //linking second and third node
    second->data = 13;
    second->next = third;
    //adding values to last node
    third->data =234;
    third->next  = head;//circular linked list
    linkedlisttraversal(head);
    fourth->data = 23;
    fourth->next = NULL;
    head = insertathead(head,fourth);
    linkedlisttraversal(head);
    return 0;
}