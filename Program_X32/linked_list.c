#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int n;

typedef struct Node link;


void display(struct link *start)
{
	link *ptr;
	ptr=start;
	n=0;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		n++;
	}
}

void insert(struct link **start)
{
	int pos;
	printf("\nEnter position to be inserted :");
	scanf("%d",&pos);
	int item;
	printf("\nEnter data to be inserted :");
	scanf("%d",&item);
	if (pos==1)
	{
		link *new_node;
		new_node = ( link*)malloc(sizeof(link));
		new_node -> data = item;
		new_node -> next = *start;
		*start = new_node;
	}
	else if (pos>1 && pos<n)
	{
		link *new_node, *ptr, *preptr;
		new_node = (link*)malloc(sizeof(link));
		new_node -> data = item;
		ptr = *start;
		preptr = ptr;
		for(int i=1; i<pos; i++)
		{
 			preptr = ptr;
 			ptr = ptr -> next;
		}
		preptr -> next=new_node;
		new_node -> next = ptr;
	}
	else if (pos==n)
	{
		link *ptr, *new_node;
		new_node = (link*)malloc(sizeof(link));
		new_node -> data = item;
		new_node -> next = NULL;
		ptr = *start;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		ptr -> next = new_node;
	}	
}

void delete(link **start){
	int pos;
	printf("\nEnter position to be deleted :");
	scanf("%d",&pos);
	if (pos==1)
	{
		link *ptr1;
		ptr1 = *start;
        *start = (*start)->next;
        free(ptr1);
	}
	else if (pos>1 && pos<n)
	{
		link *ptr, *preptr;
		ptr = *start;
		
		for(int i=1; i<pos; i++)
 		{
 			preptr = ptr;
 			ptr = ptr -> next;
 		}
 		preptr -> next = ptr -> next;
 		free(ptr);
	}
	else if (pos==n)
	{
		link *ptr, *preptr;
		ptr = *start;
		while(ptr -> next != NULL)
		{
 			preptr = ptr;
 			ptr = ptr -> next;
		}
		preptr -> next = NULL;
		free(ptr);
	}
	
}

void search(link *start)  
{  
    link *ptr;  
    int item,i=0,flag;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\nThe list is Empty.\n");  
    }  
    else  
    {   
        printf("\nEnter the element to search:\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("Element found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
    }     
 
} 

int main(){

	//creation code
	printf("\n****** CREATE YOUR LINKED LIST ******\n");
	link *ptr, *start;
	int item;
	char ch;
	ptr=(link*)malloc(sizeof(link));
	ptr->next=NULL;
	start=ptr;
	printf("Enter Data :\n");
	scanf("%d",&item);
	ptr->data=item;
	printf("Do you want to add more Data: \n");
	fflush(stdin);
	scanf("%c",&ch);
	while(ch=='y'||ch=='Y'){
		ptr->next=(link*)malloc(sizeof(link));
		ptr=ptr->next;
		printf("Enter Data: \n");
		scanf("%d",&ptr->data);
		printf("Do you want to add more Data: \n");
		fflush(stdin);
		scanf("%c",&ch);	
	}
	ptr->next=NULL;
	ptr=start;

	//driving code
	int choice;
	while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){	
	 case 1: insert(&start);display(start); break;
	 case 2: delete(&start);display(start); break;
	 case 3: display(start); break;
	 case 4: search(start); break;
	 case 5: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
    }
	
	
	return 0;
}