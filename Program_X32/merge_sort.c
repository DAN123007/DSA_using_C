#include<stdio.h>
#define MAX 20
 
void mergesort(int *, int, int);
int merge(int *, int, int, int);
 
int main()
{
   int arr[MAX];
   int n, i;
   printf("Enter the size of array: ");
   scanf("%d", &n);
   printf("Enter the array:\n");
   for(i=0; i<n; i++)
       scanf("%d", &arr[i]);
 
   mergesort(arr, 0, n-1);
 
   printf("After merge sort:\n");
   for(i=0; i<n; i++)
       printf("%d ", arr[i]);
   printf("\n");
 
   return 0;
}
 
int merge(int *arr, int l, int mid, int h)
{
   int i = l, j = mid+1, k = l;
   int temp[MAX];
   while(i<=mid && j<=h)
   {
       if(arr[i] < arr[j])
       {
           temp[k] = arr[i];
           i++;
       }
       else
       {
           temp[k] = arr[j];
           j++;
       }
       k++;
   }
   if(i>mid)
   {
       while(j<=h)
       {
           temp[k] = arr[j];
           j++;
           k++;
       }
   }
   if(j>h)
   {
       while(i<=mid)
       {
           temp[k] = arr[i];
           i++;
           k++;
       }
   }
 
   while(l <= h)
   {
       arr[l] = temp[l];
       l++;
   }
}
 
void mergesort(int *arr, int l, int h)
{
   int mid;
   if(l < h)
   {
       mid = (l+h)/2;
 
       mergesort(arr, l, mid);
       mergesort(arr, mid+1, h);
 
       merge(arr, l, mid, h);
   }
}
