#include <stdio.h>
#include <stdlib.h>
#define capacity 20

int queue[capacity];
int front = -1, rear = -1;

int checkFull(){
    if ((front == rear + 1) || (front == 0 && rear == capacity - 1)){
        return 1;
    }
    return 0;
}

int checkEmpty(){
    if (front == -1) 
    {
        return 1;
    }
  return 0;
}

void enqueue(int value){
    if (checkFull())
        printf("Overflow condition\n");
    
    else
    {
        if (front == -1) 
            front = 0;
        
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        printf("%d was enqueued to circular queue\n", value);
  }
}

int dequeue() {
    int variable;
    if (checkEmpty()) {
        printf("Underflow condition\n");
        return -1;
    } 
    else
    {
        variable = queue[front];
        if (front == rear) {
            front = rear = -1;
    } 
    else {
      front = (front + 1) % capacity;
    }
    printf("%d was dequeued from circular queue\n", variable);
    return 1;
  }
}

void print(){
    int i;
    if (checkEmpty())
        printf("Nothing to dequeue\n");
    else
    {
        printf("\nThe queue looks like: \n");
        for (i = front; i != rear; i = (i + 1) % capacity)
        {
            printf("%d ", queue[i]);
        }
    printf("%d \n\n", queue[i]);

  }
}

int main() {
  int choice,val;
	while(1){
      printf("\n****** MENU ******\n");
      printf("1. EnQueue\n2. DeQueue\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){	
	 case 1: printf("Enter Value to be Inserted:");scanf("%d",&val);enqueue(val);break;
	 case 2: dequeue();break;
	 case 3: print(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
    }

  return 0;
}

