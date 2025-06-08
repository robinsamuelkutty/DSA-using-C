#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;
typedef struct stack{
    int size;
    node * top;
}stack;


int isempty(stack *s);
int infull(stack *s);
void push(stack *s,int element);
int pop(stack*s);
int peek(stack *s,int i);
int stackbottom(stack*s);
int stacktop(stack *s);

// //cwh code
// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next; 
//     }
// }

int main(void)
{
    
    stack *s = malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;
    
    int i;
    while(i!=5){
    printf("\n1.push\n2.Pop\n3.peek\n4.bottomtop\n5.Exit\n");
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
            push(s,val);
        }
    }
    else if(i == 2)
    {
                printf("No. of elements: ");
        int b;
        scanf("%i",&b);
        for(int j = 1; j<=b;j++)
        {
            int val = pop(s);
            printf("Stack no. %i : %i popped. %i stacks remain\n ",j,val,s->size);
        }
    }
    else if(i==3)
    {
        printf("1.Peek all elements\n2.Peek a single element\n");
        int b;
        scanf("%i",&b);
        if(b == 1)
        {
            for(int k = 1;k<=s->size;k++)
            {
                int val = peek(s,k);
                printf("stack %d : %d\n",k,val);
            }
        }
        else
        {
            printf("Enter no: ");
            int b;
            scanf("%i",&b);
            int val = peek(s,b);
            printf("stack %d : %d",b,val);
        }
    }
    else if(i==4)
    {
        printf("stackbottom: %d\nstacktop: %d\n",stackbottom(s),stacktop(s));
    }
    }
}
int isempty(stack *s)
{
    if(s->top == NULL)
    {
        return 1;
        
    }
    return 0;
}
int isfull(stack *s,node * ptr)
{
    if(ptr == NULL)
    {
        return 1;
        
    }
    return 0;
}
void push(stack *s,int element)
{
    node * ptr = malloc(sizeof(node));
    if(isfull(s,ptr))
    {
        printf("Stack is full\n");
        return;
    }
    ptr->data = element;
    // printf("%d element\n",ptr->data);
    ptr->next=s->top;
    s->top = ptr;
    s->size += 1;
    printf("%i pushed into stack\n",s->top->data);
}
int pop(stack*s)
{
    if(isempty(s))
    {
        printf("Stack is empty.Cannot pop\n");
        return -1;
    }
    node * ptr = s->top;
    s->top = ptr->next;
    int data = ptr->data;
    s->size -=1;
    free(ptr);
    return data;
};
int peek(stack *s,int i)
{
    node * ptr = s->top;
    for(int j = 0; (j<i-1 && ptr!=NULL);j++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
    return ptr->data;
    }
    else
    {
        return -1;
    }
};
int stackbottom(stack*s)
{   node * i;
    for(i = s->top;i->next!= NULL; i = i->next)
    {
        continue;
    }
    return i->data;

}
int stacktop(stack *s)
{
    return s->top->data;
}
