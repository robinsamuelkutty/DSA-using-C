#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node;

void linkedlisttraversal(Node * ptr)
{
    for(Node* i = ptr; i!= NULL; i=i->next)
    {
        printf("%d ",i->data);
    }
    printf("\n");
}
Node * insertAtBeginning(Node * head,int data);
Node * insertAtIndex(Node * head,int data,int index);
Node * insertAtEnd(Node * head,int data);
Node * insertAfterNode(Node * prevnode,int data);
Node * deletefrombeginning(Node * head);
Node * deleteatindex(Node * head,int index);
Node * deleteatend(Node* head);
Node * deletegivenvalue(Node * head,int value);
int main()
{
    Node * head;
    Node * second;
    Node * third;
    //allocate memory for linked list in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    //assigning values
    //linking first and second node 
    head->data = 7;
    head->next = second;
    //linking second and third node
    second->data = 13;
    second->next = third;
    //adding values to last node
    third->data =234;
    third->next  = NULL;
    linkedlisttraversal(head);
    head = insertAtBeginning(head,5);
    linkedlisttraversal(head);
    head = insertAtEnd(head,1000);
    linkedlisttraversal(head);
    head = insertAtIndex(head,222,2);
    linkedlisttraversal(head);
    head = insertAfterNode(head->next,555);
    linkedlisttraversal(head);
    deletefrombeginning(head);
    linkedlisttraversal(head);
    deleteatindex(head,0);
    linkedlisttraversal(head);
    deleteatend(head);
    linkedlisttraversal(head);
    printf("\n");
    deletegivenvalue(head,234);
    linkedlisttraversal(head);
    
     
}

/*
linked list insertion
1.Insert at beginning O(1)
2.Insert in between O(n)
3.Insert at end O(n)
4.Insert after a given node O(1)
*/

Node * insertAtBeginning(Node * head,int data)
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    
    tmp->next = head;
    head = tmp;
    return head;
}
Node * insertAtIndex(Node * head,int data,int index)
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    
    Node * p = head;
    for(int i = 0; i <index-1;i++)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
    return head;

}
Node * insertAtEnd(Node * head,int data)
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    
    Node * p;
    for(p = head; p->next != NULL ;p = p->next)
    {
        continue;
    }
    tmp->next = NULL;
    p->next = tmp;
    return head;

}
Node * insertAfterNode(Node * prevnode,int data)
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    
    tmp->next = prevnode->next;
    prevnode->next = tmp;

}
/*
linked list insertion
1.Delete the first node  at beginning O(1)
2.Delete a node in between O(n)
3.Delete a node at the end O(n)
4.Delete a node with  given value O(n)
*/
Node * deletefrombeginning(Node * head)
{
    Node * tmp =head->next;
    *head = * tmp;
    free(tmp);
}

Node * deleteatindex(Node * head,int index)
{
    Node * p = head;
    for(int i = 0; i <index;i++)
    {
        p = p->next;
    }
    Node * tmp = p->next;
    *p = *tmp;
    free(tmp);
}

Node * deleteatend(Node* head)
{
    Node * p = head;
    for(p = head; p->next->next!=NULL;p = p->next)
    {
        continue;
    }
    // printf("\n");
    // printf("%d\n",p->data);
    Node * tmp = p->next;
    p->next = NULL;
    free(tmp);
}
Node * deletegivenvalue(Node * head,int value)
{
    Node * p = head;
    //case 1: value at beginning 
    if(p->data == value)
    {
        deletefrombeginning(head);
        return head;
    }
    //case 2: for all other elements
    for(p = head; p->next->data!=value && p->next->next != NULL;p = p->next)
    {
        continue;
    }
    //case 2.1: if not in list
    // printf("%d",p->data);
    if(p->next->next == NULL && p->next->data != value)
    {
        printf("Element not in list to delete\n");
        return head;
    }
    //case 2.2: if element in list
    Node * tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}