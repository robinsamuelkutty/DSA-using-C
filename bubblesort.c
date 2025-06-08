/*
time complexity O(n^2)
stable algo - yes
recursive - no
adaptive - not by default(can be made adaptive) (count the number of swaps required if no swaps then )

it is called bubble sort lighter(smaller) elements bubble up to the top of the array and the heavy(bigger) elements sink 
to the end of the array.

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
void bubblesort(int a[],int n)
{
    for(int i = 0;i<n-1; i++) // for number of passes
    {   int count = 0;
        for(int j = 0; j<n-i-1;j++) // for each comparison
        {
            
            if(a[j]>a[j+1])
            {
                int tmp;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                count++;
            }
        }
        if(count == 0)  // makes the program adaptive. as soon as it becomes sorted it returns
        {
            return;
        }
        printf("Pass %d: ",i+1);
        printarray(a,n);
        printf("\n");
    }
}

int main()
{
    int A[] = {5,324,56,675,3,23,233,34534,123454,534343,25545,32444};
    int n = 12;
    printarray(A,n);//printing the array before sorting
    bubblesort(A,n);//sort the array
    printarray(A,n);//printing the array after sorting 

}