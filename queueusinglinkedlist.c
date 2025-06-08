#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

typedef struct queue
{
    node * r;
    node * f;
    int size;
}queue;
void enqueue(queue * ptr,int element);
int dequeue(queue *ptr);
int peek(queue * ptr,int  elementno);

int main()
{
    queue * q = malloc(sizeof(queue));
    q->f = NULL;
    q->r = NULL;
    q->size = 0;


    
    int i=0;
    while(i!=5){
    printf("\n1.Enqueue\n2.Dequeue\n3.peek\n5.Exit\n");
    scanf("%i",&i);
    if(i == 1)
    {
        printf("No. of elements: ");
        int b;
        scanf("%i",&b);
        for(int j = 1; j<=b;j++)
        {
            int val;
            printf("Element %i : ",j); 
            scanf("%i",&val);
            enqueue(q,val);
        }
    }
    else if(i == 2)
    {
                printf("No. of elements: ");
        int b;
        scanf("%i",&b);
        for(int j = 1; j<=b;j++)
        {
            int val = dequeue(q);
            printf("Queue no. %i : %i dequeued. %i items remain in queue\n ",j,val,q->size);
        }
    }
    else if(i==3)
    {
        printf("1.Peek all elements\n2.Peek a single element\n");
        int b;
        scanf("%i",&b);
        if(b == 1)
        {
            for(int k = 1;k<=q->size;k++)
            {
                int val = peek(q,k);
                printf("Queue %d : %d\n",k,val);
            }
        }
        else
        {
            printf("Enter no: ");
            int b;
            scanf("%i",&b);
            int val = peek(q,b);
            printf("queue %d : %d",b,val);
        }
    }
    else if(i==4)
    {
        printf("lastinqueue: %d\nfirstinqueue: %d\n",q->f->data,q->r->data);
    }
    }
}


void enqueue(queue * ptr,int element)
{
    node * n = malloc(sizeof(node));
    if(n == NULL)
    {
        printf("Queue is full\n");
        return;
    }
    n->data = element;
    n->next = NULL;
    if(ptr->f == NULL)
    {
        ptr->r = ptr->f = n;
    }
    else
    {
        ptr->r->next = n;
        ptr->r = n;
    }
    ptr->size++;
}
int dequeue(queue *ptr)
{
    if(ptr->f == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    node * tmp = ptr->f;
    ptr->f = ptr->f->next;
    int data = tmp->data;
    free(tmp);
    ptr->size--;
    return data;
}
int peek(queue * ptr,int elementno)
{
    int val = -1;
    node * i = ptr->f;
    int j = 1;
    for(j = 1;j<elementno;j++)
    {
        i = i->next;
    }
    return i->data;
}