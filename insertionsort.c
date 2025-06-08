/*
1st pass - 1comparison 1 possible swap
2nd pass - 2comparison 2 possible swap
3rd pass - 3comparison 3 possible swap ,total passes = n-1

time complexity = O(n^2)
best case = O(n) adaptive one comparison per pass
stable - yes
intermediate result is not useful
adaptive - yes by nature.

it is called insertion sort because we pick up an element and insert it into its right place in the 
already sorted array at its left. (from second element to last element)

*/

#include <stdio.h>
void printarray(int a[],int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insertionsort(int a[],int n)
{
    for(int i = 1;i<n; i++) // for number of passes
    {   
        int tmp = a[i]; //element to be inserted
        int j = i-1;
        
        // for(int j = i-1;j>=-1;j--)//loop for each pass //my code
        // {
        //     if(j==-1)
        //     {
        //         a[j+1] = tmp;

        //     }
        //     else if(tmp<a[j])
        //     {
        //         a[j+1] = a[j];
        //     }
        //     else
        //     {
        //         a[j+1] = tmp;
        //         break;
        //     }
        // // }
        // for(j = i-1;j>=0;j--)//loop for each pass //my code
        // {

        //     if(tmp<a[j])
        //     {
        //         a[j+1] = a[j];
        //     }
        //     else
        //     {

        //         break;
        //     }
        // }
        // a[j+1] = tmp;

        while(j>= 0 && a[j]>tmp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        printf("Pass %d: ",i);
        printarray(a,n);
        // printf("\n");
    }
}

int main()
{
    int A[] = {5,6,2,1,4,3,12,7,9,8,11,10};
    int n = 12;
    printarray(A,n);//printing the array before sorting
    insertionsort(A,n);//sort the array
    printarray(A,n);//printing the array after sorting 

}