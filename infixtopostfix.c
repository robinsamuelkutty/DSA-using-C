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
void push(stack *s,char a);
char pop(stack *s);

int prec(char a);
int isoperator(char a);
int main()
{
    stack *s = malloc(sizeof(stack));
    s->top = NULL;
    s->size = 0;
    push(s,' ');
    char * infix = "x-y/z-k*d";
    int len = strlen(infix);
    char postfix[len+1];
    // printf("%d\n",len);
    int i = 0;
    int j = 0;
    while(i<len)//iterating over each character
    {
        char t = infix[i];
        // printf("%c",t);
        if(!isoperator(t))
        {
            postfix[j] = infix[i];
            i++;j++;
        }
        else
        {
            if(prec(t)>prec(s->top->c))
            {
            //    printf("code came here.");
                push(s,t);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isempty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    
    postfix[j] = '\0';

    int k = 0;
    while(postfix[k]!= '\0')
    {
        printf("%c",postfix[k]);
        k++;
    }
    printf("\n");

        
}

int prec(char a)
{
    if(a == '*' || a =='/')
    {
        return 3;
    }
    else if(a == '+' || a == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isoperator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/' )
    {
        return 1;
    }
    return 0;
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

