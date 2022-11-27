#include<stdio.h>

void insertion(int *, int);

int main()
{
    int n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    insertion(arr, n);

    return 0;
}

void insertion(int *arr, int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        temp = arr[i];
        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }

    printf("After insertion sort:\n");
    for(i=0; i<n; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}