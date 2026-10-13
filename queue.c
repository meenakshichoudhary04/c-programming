#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *createnewnode(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;         
}
void enqueue(struct node **front, struct node **rear, int value)
{
    struct node *newnode=createnewnode(value);
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        if(*rear==NULL)
        {
            *front=newnode;
            *rear=newnode;
        }
        else
        {
            (*rear)->next=newnode;
            *rear=newnode;
        }
    }
}
int dequeue(struct node **front, struct node **rear)
{
    if(*front==NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        struct node *temp=*front;
        int dequeued_data=temp->data;
        *front=(*front)->next;
        if(*front==NULL)
        {
            *rear=NULL;
        }
        free(temp);
        return dequeued_data;
    }
}
void display(struct node *front)
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
} 
int main()
{
    struct node *front=NULL;
    struct node *rear=NULL;
    int choice, value;  
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d",&value);
                enqueue(&front,&rear,value);
                break;
            case 2:
                value=dequeue(&front,&rear);
                if(value!=-1)
                {
                    printf("Dequeued value: %d\n",value);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } 
    return 0;
}