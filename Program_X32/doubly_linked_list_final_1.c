#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
int n;
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);

int main()
{
    int pos;
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create");
        printf("\n 2: Display");
        printf("\n 3: Insert");
        printf("\n 4: Delete");
        printf("\n 5: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n DOUBLY LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            printf("Enter the postion you want to insert :\n");
            scanf("%d", &pos);
            if(pos==1){
               start = insert_beg(start); 
            }
            else if(pos>1 && pos<n){
                start = insert_after(start);
            }
            else if(pos == n){
                start = insert_end(start);
            }
            start = display(start);
            break;
        case 4:
            printf("Enter the postion you want to delete :\n");
            scanf("%d", &pos);
            if(pos==1){
               start = delete_beg(start); 
            }
            else if(pos>1 && pos<n){
                start = delete_after(start);
            }
            else if(pos == n){
                start = delete_end(start);
            }
            start = display(start);
            break;
        }
    } while (option != 5);
    getch();
    return 0;
}
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node-> data = num;
            while (ptr-> next != NULL)
                ptr = ptr-> next;
            ptr-> next = new_node;
            new_node-> prev = ptr;
            new_node-> next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    n=0;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
        n++;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}
