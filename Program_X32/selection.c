#include<stdio.h>
#include<stdlib.h>

int samllest(int [], int, int);
void selection_sort(int [], int);

int main(){
    
    int i,n;
    printf("Enter Number of Elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements of the array :\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    selection_sort(arr,n);

    printf("Sorted Array is:\n");
        for (i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }

    return 0;

}

int smallest(int arr[], int k, int n)
{
    int pos=k, small=arr[k];
    for (int i = k+1; i < n; i++)
    {
        if(arr[i]<small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
    
}

void selection_sort(int arr[], int n)
{
    int k, pos, temp;

    for (k=0; k<n; k++){
        pos = smallest(arr, k , n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}