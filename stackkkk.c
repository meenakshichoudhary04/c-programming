#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnewnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void push(struct node **top, int data)
{
    struct node *newnode = createnewnode(data);
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
       
    }
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
}
int pop(struct node **top)
{
    if(*top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        struct node *temp = *top;
        int popped_data = temp->data;
        *top = (*top)->next;
        free(temp);
        return popped_data;
    }
}   
int peek(struct node *top)
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}
void display(struct node *top)
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp = top;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    struct node *top = NULL;
    int choice, data;
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if(data != -1)
                    printf("Popped element: %d\n", data);
                break;
            case 3:
                data = peek(top);
                if(data != -1)
                    printf("Top element: %d\n", data);
                break;
            case 4:
                display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}