#include<stdio.h>
#include<stdlib.h>
 struct node
{
    int data;
    struct node *next;
};
struct node* createnewnode(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void insertionAtFirst(struct node** head,int value)
{
    struct node* newnode=createnewnode(value);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        newnode->next=*head;
        *head=newnode;
    }
}
void reverse(struct node** head)
{
    struct node* prev=NULL;
    struct node* current=*head;
    struct node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}       
int main()
{
    struct node* head=NULL;
    int n,value;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&value);
        insertionAtFirst(&head,value);
    }
    printf("Original linked list: ");
    display(head);
    reverse(&head);
    printf("Reversed linked list: ");
    display(head);
    return 0;
}