#include <stdio.h>
void bubble(int y[],int x){
    int i,temp,m;
    for (i = 0; i < x - 1; i++)
    {
        for (m = 0; m < x - i - 1; m++)
        {
            if (y[m] > y[m + 1])
            {
                temp = y[m];

                y[m] = y[m + 1];

                y[m + 1] = temp;
            }
        }
   }     
        printf("Sorted Array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d", y[i]);
            printf("\n");
        }
}
int main()
{
    int x;
    printf("Enter Number of Elements:\n");
    scanf("%d", &x);
    int y[x];
    int i;
    for (i = 0; i < x; i++)
    {
        printf("Enter Elements:\n");
        scanf("%d", &y[i]);
    }
    bubble(y , x);
    
}