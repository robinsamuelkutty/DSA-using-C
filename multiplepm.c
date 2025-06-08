#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//{[()]} - different types of brackets match the type of bracket while popping

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
void push(stack *s,char a);you
char pop(stack *s);

int main()
{
    stack *s = malloc(sizeof(stack));
    s->top = NULL;
    s->size = 0;
    char * expr = "(7-11 +{23-8*2} -[33+1])";
    int len = strlen(expr);
    for(int i = 0;i<len;i++)//iterating over each character
    {
        char t = expr[i];
        if(t=='(' || t == '[' || t == '{')
        {
            push(s,t);
        }
        else if(t == ')' || t == ']' || t == '}')
        {
            char x = pop(s);
            if(x == '0')
            {
                printf("Expression is unbalanced using condition 1\n");
                return 0;
            }
            else if ((t == ')' && x == '(') || (t == ']' && x == '[') || (t == '}' && x == '{'))
            {
                continue;
            }
            else
            {
                printf("Expression is unbalanced using condition 3\n");
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
char pop(stack *s)
{
        if(isempty(s))
    {
        printf("Stack is empty\n");
        return '0';
    }
    node * ptr = s->top;
    s->top = ptr->next;
    int data = ptr->c;
    s->size -=1;
    free(ptr);
    return data;
}

