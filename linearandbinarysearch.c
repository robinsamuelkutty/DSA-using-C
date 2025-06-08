#include<stdio.h>

int linearsearch(int arr[],int size, int element)
{
    for(int i = 0; i<size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }

    }
    return -1;
}
int binarysearch(int arr[],int size, int element)
{
    int low,mid,high;
    low = 0;
    high = size-1;
    while(low<=high)
    {
        mid = (low+high)/2;

        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid]< element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }  
    return -1;
}


int main(void)
{   //unsorted array for linear search
    // int arr[] = {1,2,5,53,4,34,65,456,456,3,4,53,6,4,6,7,8,9,1323,5465};
    // int size = sizeof(arr)/sizeof(int);
    
    
    int arr[] = {1,2,34,45,564,755,988,2454,6578,9243,10000,143434};
    int size = sizeof(arr)/sizeof(int);
    printf("Element to be searched: ");
    int element;
    scanf("%d",&element);
    // int searchindex = linearsearch(arr,size,element);
    int searchindex = binarysearch(arr,size,element);
    printf("The element was found at index %d",searchindex);
}