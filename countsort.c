 /*
 analysis
 takes extra space
 time complexity O(max+n) which is nearly O(n) because for a very large array max<<n; this comes at the 
 cost of space

 */
 
 #include <stdio.h>
 #include <stdlib.h>

void printarray(int a[],int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void countsort(int arr[],int n)
{
    //finding the maximum element in arr
    int max = arr[0];
    for(int i = 0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    // int * B = malloc(sizeof(int)*(max+1));
    int B[max+1];
    // printf("%d\n",max);

    //initialising all indices of B to 0;
    for(int i = 0;i<=max; i++)
    {
        B[i] = 0;
    }

    //traversing the first array and incrementing in B
    for(int i = 0; i<n; i++)
    {
        B[arr[i]]++;
    }
    // printarray(B,max+1);

    //putting the values back into arr by traversing through B
    int replindex = 0;
    for(int i = 0;i<max+1;i++)
    {
        while(B[i]>0){
        //   printf("%d,",i);
            arr[replindex] = i;
            replindex++;
            B[i] -=1;
        }
        // printf("\n");
    }

}









int main()
{
    int A[] = {5,6,2,1,4,3,12,7,9,8,11,10};
    int n = 12;
    printarray(A,n);//printing the array before sorting
    countsort(A,n);//sort the array
    printarray(A,n);//printing the array after sorting 

}