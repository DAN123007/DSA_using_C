#include<stdio.h>

#define MAX_SIZE 5

void binary_search(int[],int,int);

int main() {
    int m;
    printf("Enter a lenght of the array:\n");
    scanf("%d",&m);
    int arr_search[m], i,element;

    //printf("Simple Binary Search Example - Array and Functions\n");
    printf("\nEnter %d Elements for Searching : \n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &arr_search[i]);

	printf("Enter Element to Search : ");
    scanf("%d", &element);
   

    binary_search(arr_search,element,m);
    
}

void binary_search(int fn_arr[],int element,int m) {
   int f = 0, r = m,mid;
   
   while (f <= r) {
	  mid = (f+r)/2;

	  if (fn_arr[mid] == element) {
         printf("\nSearch Element  : %d  : Found :  Position : %d.\n", element, mid+1);
         break;
	  }
      else if (fn_arr[mid] < element)
         f = mid + 1;    
      else
         r = mid - 1;
   }
   
   if (f > r)
      printf("\nSearch Element : %d  : Not Found \n", element);
}