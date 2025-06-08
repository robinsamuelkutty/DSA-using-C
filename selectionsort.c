/*
Selection sort - we find the smallest element in the array and then insert it at the start.

no. of passes - n-1 where n is length of array
no of comparisons - n-1 +n-2....3+2+1 = n(n-1)/2
worst case time complexity = O(n^2)
swaps - 0 to n-1 every pass can only do one pass.
adaptive - not adaptive
stability- not stable
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
void selectionsort(int a[],int n)
{   int tmp;
    for(int i = 0;i<n-1; i++) // for number of passes
    {   
        // tmp = a[i];
        int tmp_index = i;
        // printf("tmp %d\n",tmp);
        for(int j = i+1; j<n;j++) // for each comparison
        {
            if(a[tmp_index]>a[j])
            {
                // tmp = a[j]; //selecting the smallest element
                tmp_index = j; //selecting its index
            }
        }
        tmp = a[tmp_index]; // assigning the smallest value to tmp
        a[tmp_index] = a[i]; //putting the value of ith element at the smallest element's place
        a[i] = tmp; //putting the smallest element at the start.

        printf("Pass %d: ",i+1);
        printarray(a,n);
    }
}

int main()
{
    int A[] = {5,6,2,1,4,3,12,7,9,8,11,10};
    int n = 12;
    printarray(A,n);//printing the array before sorting
    selectionsort(A,n);//sort the array
    printarray(A,n);//printing the array after sorting 

}