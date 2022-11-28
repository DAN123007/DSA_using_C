#include <stdio.h>
#include<stdlib.h> 
#define MAX 5
 
void insert();
void delete_q();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: insert();
            		break;
            case 2: delete_q();
            		break;
            case 3: display();
            		break;
            case 4:	exit(0);
            
			default: 	printf("Wrong choice \n");
						break;
        } 
    }
	return 0; 
} 
 
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    {
    	printf("\nQueue Overflow \n");
    	return;
	}
    printf("Inset the element in queue : ");
    scanf("%d", &add_item);
    if (front == - 1 && rear == -1)
    {     
        front++;
        queue_array[++rear] = add_item;
    }
    else
    	queue_array[++rear] = add_item;
} 
 
void delete_q()
{
    if (front == - 1 || front > rear)
    {
        printf("\nQueue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}
 
void display()
{
    int i;
    if (front == - 1)
        printf("\nQueue is empty \n");
    else
    {
        printf("\nQueue is :");
        for (i = front; i <= rear; i++)
            printf("\t %d ", queue_array[i]);
        printf("\n");
    }
}