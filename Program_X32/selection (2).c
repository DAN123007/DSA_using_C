#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    //for setting minimum index
    //i is no. of steps
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        
        //checking for smallest element
        //n for index not for no. of element
        //not get confused
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_idx]){
            min_idx = j;
          }
        }
 
        
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
    printf("Sorted array is :\n");
    for (i = 0; i < n; i++){
        printf("%d\n",arr[i]);
    }
}
int main()
{
    int n; 
    printf("Enter number of elements :\n ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements of array :\n");
    for (int i=0;i<n;i++){
        printf("Enter Element %d :\n",i+1);
        scanf("%d", &arr[i]);
        
    }
    selectionSort(arr, n);
    return 0;
}

