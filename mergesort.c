/*
recursive merge sort;
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
void merge(int arr[],int low,int mid,int high)
{
    int i = low,j = mid +1,k= low;//i-first element of first array j -first element of second array k-merge tracker
    int B[high+1];

    while(i<=mid && j <=high)
    {
        if(arr[i]<arr[j])
        {
            B[k] = arr[i];
            i++;k++;
        }
        else
        {
            B[k] = arr[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
        B[k] = arr[i];
        k++;i++;
    }
    while(j<=high)
    {
        B[k] = arr[j];
        k++;j++;
    }
    for(int t = low;t<=high;t++)
    {
        arr[t] = B[t];
    }
}

void mergesort(int arr[],int low,int high)
{
    if(low<high){
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
    else
    {
        return;
        
    }
}

int main()
{
    int A[] = {5,6,2,1,4,3,12,7,9,8,11,10};
    int n = 12;
    printarray(A,n);//printing the array before sorting
    mergesort(A,0,n-1);//sort the array
    printarray(A,n);//printing the array after sorting 

}