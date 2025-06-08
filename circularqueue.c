#include <stdio.h>
#include <stdlib.h>

//wrong
typedef struct queue
{
    int size;
    int r;
    int f;
    int * arr;
}queue;

void enqueue(queue * ptr,int element);
int dequeue(queue * ptr);
int isfull(queue * ptr);
int isempty(queue * ptr);
int peek(queue *ptr,int position);
int first(queue *ptr);
int last(queue * ptr);

int main(void)
{  
    queue *q= malloc(sizeof(queue));
    
    q->size = 6;
   
    q->f = q->r = 0;
  
    q->arr = (int *)malloc(sizeof(int)*q->size);
    if(q->arr == NULL)
    {
        printf("malloc cant assign\n");
    }


    
    int i=0;
    while(i!=5){
    printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.firstlast\n5.Exit\n");
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
            printf("Queue no. %i : %i dequeued.\n",j,val);
        }
    }
    else if(i==3)
    {
        printf("1.Peek all elements\n2.Peek a single element\n");
        int b;
        scanf("%i",&b);
        if(b == 1)
        {   
            int k = q->f;
            while(k != q->r)
            {
                k = (k+1)%q->size;
                printf("%d,",q->arr[k]);
            }
            printf("\n");

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
        printf("lastinqueue: %d\nfirstinqueue: %d\n",last(q),first(q));
    }
    }

}

void enqueue(queue * ptr,int element)
{
    if(isfull(ptr))
    {
        printf("This Queue is full.\n");
        return;
    }

    ptr->r = (ptr->r+1)%ptr->size;
    ptr->arr[ptr->r] = element;
    return;
}

int dequeue(queue * ptr)
{
        if(isempty(ptr))
    {
        printf("This Queue is empty.\n");
        return -1;
    }

    ptr->f = (ptr->f + 1)%ptr->size;
    int element = ptr->arr[ptr->f];
    return element;
}
int isfull(queue * ptr)
{

    if(((ptr->r +1)%ptr->size) == ptr->f)
    {
        return 1;
    }
    // else if(start == 0 && end == ptr->size-1)
    // {
    //     return 1;
    // }
    // else if(ptr->f == -1 && ptr->r == ptr->size-1)
    // {
    //     return 1;
    // }
    return 0;
}
int isempty(queue * ptr)
{
    if(ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}
int peek(queue *ptr,int position)
{
    int p = (ptr->f+ position)%ptr->size;
    if(p>ptr->r && p<=ptr->f)
    {
        printf("No element at this position\n");
        return -1;
    }
    return ptr->arr[p];
}
int first(queue *ptr)
{
    return ptr->arr[ptr->f+1];
}
int last(queue * ptr)
{
    return ptr->arr[ptr->r];
}