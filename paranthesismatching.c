#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Conditions for a balanced expressions
1.While popping stack should not undewrflow
2.At End of Expressions the stack must be empty.*/
//create a linked list for all characters and stack too.
//in stack push for an opening bracket and pop for a closing bracket;

//this program only matches paranthesis and does not garuntee validity of expr eg. 8(*9-)5 is parantheisismatching

//this can be done using array also but I'm doing this through linked list.
typedef struct node
{
    char c;
    struct node * next; 
}node;

typedef struct stack
{
    node * top;
    int size;
}stack;

//functions required for stack
int isempty(stack *s);
int isfull(stack *s,node * ptr);
void push(stack *s,char a);
int pop(stack *s);

int main()
{
    stack *s = malloc(sizeof(stack));
    s->top = NULL;
    s->size = 0;
    char * expr = ")(8*7)-3-5*(7-1";
    int len = strlen(expr);
    for(int i = 0;i<len;i++)//iterating over each character
    {
        char t = expr[i];
        if(t=='(')
        {
            push(s,t);
        }
        else if(t == ')')
        {
            int x = pop(s);
            if(x == -1)
            {
                printf("Expression is unbalanced using condition 1\n");
                return 0;
            }
        }

        
    }//all characters checked
    if(isempty(s)) //checking if stack is empty
    {
        printf("Given Expression is balanced\n");
    }
    else
    {
        printf("Given expression is unbalanced using condition 2");
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
void push(stack *s,char a)
{
    node * ptr = malloc(sizeof(node));
    if(isfull(s,ptr))
    {
        printf("Stack is full\n");
        return;
    }
    ptr->c = a;
    ptr->next = s->top;
    s->top = ptr;
    s->size +=1;
    
}
int pop(stack *s)
{
        if(isempty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    node * ptr = s->top;
    s->top = ptr->next;
    int data = ptr->c;
    s->size -=1;
    free(ptr);
    return 0;
}

