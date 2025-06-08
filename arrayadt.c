#include <stdio.h>
#include <stdlib.h>
typedef struct myArray
{
    int total_size; 
    int used_size;
    int *ptr;
}myArray;

void createArray(myArray *a,int tsize,int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = malloc(tsize*sizeof(int));
    a->total_size = tsize;
    a->used_size = usize;
    a-> ptr = malloc(tsize*sizeof(int));


}

void setvalues(myArray *a)
{
    for(int i = 0; i<a->used_size;i++)
    {
        int n;
        printf("Enter element %d:",i+1);
        scanf("%d",&n);
        a->ptr[i] = n;
    }
}
void printvalues(myArray *a)
{
    for(int i = 0; i<a->used_size;i++)
    {
        printf("Element %d :%d\n",i+1,a->ptr[i]);
 

    }
}
int main(void)
{
    myArray marks;
    int tsize,usize;
    printf("Total_size: ");
    scanf("%i",&tsize);
    printf("Used_size: ");
    scanf("%i",&usize);
    createArray(&marks,tsize,usize);
    setvalues(&marks);
    printvalues(&marks);
}