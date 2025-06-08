/* partitioning procedure
i = low
j = high
pivot = low (pivot is the element that is taken as reference we will take first element for simplicity)
i++ until element > pivot is found
j-- until element<= pivot is found
swap elements at i and j
continue above until j<=i
swap the pivot element with a[j]

now sort the array on the right of the pivot and the array on the left of the pivot separately taking new 
pivot elements at the beginning of those arrays.
note- dry run a quicksort eg.

worst case - already sorted elements partitoning n-1 times
                *
            time complexity of partitioning k1n +k2
                =
            T = n-1 * k1n+k2 = O(n^2);


best case - O(logn) refer notes
        we assume the pivot element came in center of the array

stability - no

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

int partition(int *arr,int pivot,int last)
{
    int i = pivot+1;
    int j = last;
    do{ //until j exceeds i
    {
        while(arr[i]<=arr[pivot]) 
        {
            i++;
            // printf("i:%d\n",i);
        }
        while(arr[j]>arr[pivot])
        {
            j--;
            // printf("j: %d\n",j);
        }
        if(j>i)
        {
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            // printf("arj: %d\n",arr[j]);
            // printf("ari:%d\n",arr[i]);

        }
    }
    }while(j>i);
    int tmp = arr[pivot]; 
    arr[pivot] = arr[j];
    arr[j] = tmp;
    // printf("\n");
    // printarray(arr,12);
    // printf("\n");
    return j;//the position at which pivot element was kept;
}
void quicksort(int *arr,int l,int h) //l = lowest element ,h highest element
{
    if(l<h){
    int partitonindex;
    printarray(arr,9);
    partitonindex = partition(arr,l,h);
    quicksort(arr,l,partitonindex-1); // sort left sub array
    quicksort(arr,partitonindex+1,h); //sort right sub array
    }
    else{
        return;
    }
}

int main()
{
    int A[] = {3,5,2,13,12,3,2,13,45};
    int n = 9;
    printarray(A,n);//printing the array before sorting
    quicksort(A,0,n-1);//sort the array
    printarray(A,n);//printing the array after sorting 
}