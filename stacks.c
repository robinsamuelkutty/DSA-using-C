#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

int isempty(stack *a)
{
    if(a->top == -1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    return 0;

}
int isfull(stack *a,int val)
{
    if(a->size-1 == a->top)
    {
        printf("Stack is full.Cannot push %d\n",val);
        return 1;
    }
    return 0;
    
}
void push(stack *a,int element)
{
    if(isfull(a,element))
    {
        return;
    }
    a->top += 1;
    a->arr[a->top] = element;
    return;
}
int pop(stack *a)
{
    if(isempty(a))
    {
        return -1;
    }
 int tmp = a->arr[a->top];
    a->top -= 1;
    return tmp;

}
int peek(stack *a,int i)
{
    if(a->top-i+1<0)
    {
        printf("Invalid position.\n");
        return -1;
    }
    return a->arr[a->top-i+1];
    
}

int stackBottom(struct stack* sp){
    return sp->arr[0];
}
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}



int main(void)
{
    stack *s = malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->arr = malloc(s->size*sizeof(int));

    printf("Before pushing, Full: %d\n", isfull(s,2));
    printf("Before pushing, Empty: %d\n", isempty(s));
    printf("\n");

    push(s, 1);
    push(s, 23);
    push(s, 99);
    push(s, 75);
    push(s, 3);
    push(s, 64);
    push(s, 57);
    push(s, 46);
    push(s, 89);
    push(s, 6); // ---> Pushed 10 values 
    push(s, 46); // Stack Overflow since the size of the stack is 10
    printf("\n");
    printf("After pushing, Full: %d\n", isfull(s,2));
    printf("After pushing, Empty: %d\n", isempty(s));
    printf("\n");
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("\n");
    // printf("%d\n",s->top);
    for(int j = 1; j<= s->top+1;j++)
    {
        printf("The value at position %d from top is %d\n",j,peek(s,j));
    }
    printf("stack top: %d\n",stackTop(s));
    printf("stack bottom: %d\n",stackBottom(s));




}