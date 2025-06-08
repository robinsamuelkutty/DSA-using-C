#include <stdio.h>

void display(int arr[],int size)
{
    //traversal in an array
    for(int i = 0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int indinsert(int arr[],int * size,int element,int index,int capacity)
{
    //code for insertion
    if(*size>=capacity)
    {
        return  -1;
    }
    for(int i = *size-1; i>=index;i--)
    {
        arr[i+1] = arr[i];

    }
    arr[index] = element;
    *size +=1;
    return 1;
}

int inddelete(int arr[],int * size,int index,int capacity)
{   
    //code for deletion
    if(index>=capacity)
    {
        return  -1;
    }
    for(int i = index; i<*size -1;i++) //we only need to reach the second last element to shift all elements.
    {
        arr[i] = arr[i+1];

    }
    *size -=1;
    return 1;
}

int main(void)
{
    int arr[100] = {1,3,5,23,34};
    int size = 5,element = 45,index = 2;
    display(arr,size);
    indinsert(arr,&size,element,index,100);
    display(arr,size);
    index = 4;
    inddelete(arr,&size,index,100);
    display(arr,size);
}