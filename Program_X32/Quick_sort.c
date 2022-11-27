#include<stdio.h>

void quick(int *, int, int);
int pivot(int *, int, int);
void swap(int*, int*);

int main()
{
    
    int n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    quick(arr, 0, n-1);

    printf("After quick sort:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int pivot(int *arr, int l, int h)
{
    int p = arr[h];
    int i = l-1, j;

    for(j = l; j<h; j++)
    {
        if(arr[j] < p)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[h]);
    return (i);
}

void quick(int *arr, int l, int h)
{
    int p;
    if(l < h)
    {
        p = pivot(arr, l, h);

        quick(arr, l, p-1);
        quick(arr, p+1, h);
    }
}