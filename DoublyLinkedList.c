#include<stdio.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* createnewnode(int value) {
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->next= NULL;
    newnode->prev= NULL;
    return newnode;
} 
void IAF(struct node **head, int value) {
    struct node *newnode= createnewnode(value);
    newnode->next= *head;
    if(*head== NULL) {
        *head= newnode;
    }
    else {
        (*head)->prev= newnode;
        newnode->next= *head;
        *head= newnode;
    }
    
}
void IAL(struct node **head, int value) {
    struct node *newnode= createnewnode(value);
    if(*head== NULL) {
        *head= newnode;
    }
    else {
        struct node *temp= *head;
        while(temp->next!= NULL) {
            temp= temp->next;
        }
        temp->next= newnode;
        newnode->prev= temp;
    }
}
void IBGV(struct node **head, int value, int x) {
    struct node *newnode;
    
    
        
}
    
int main()