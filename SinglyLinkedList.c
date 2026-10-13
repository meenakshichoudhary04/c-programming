#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node* createnewnode(int value) {
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= value;
    newnode->next= NULL;
    return newnode;
} 
void IAF(struct node **head, int value) {
    struct node *newnode= createnewnode(value);
    newnode->next= *head;
    *head= newnode;
}
void IAL(struct node **head, int value) {
    struct node *newnode= createnewnode(value);
    if(*head== NULL) {
        *head= newnode;
        return;
    }
    struct node *temp= *head;
    while(temp->next!= NULL) {
        temp= temp->next;
    }
    temp->next= newnode;
}
void IBGV(struct node **head, int value, int pos) {
    struct node *newnode= createnewnode(value);
    if(pos== 1) {
        newnode->next= *head;
        *head= newnode;
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newnode->next= temp->next;
    temp->next= newnode;
}
void IAGV(struct node **head, int value, int pos) {
    struct node *newnode= createnewnode(value);
    if(pos== 1) {
        newnode->next= *head;
        *head= newnode;
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newnode->next= temp->next;
    temp->next= newnode;
}
void insertAtPosition(struct node **head, int value, int pos) {
    struct node *newnode= createnewnode(value);
    if(pos== 1) {
        newnode->next= *head;
        *head= newnode;
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newnode->next= temp->next;
    temp->next= newnode;
}
void DAF(struct node **head) {
    if(*head== NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp= *head;
    *head= (*head)->next;
    free(temp);
}
void DAL(struct node **head) {
    if(*head== NULL) {
        printf("List is empty\n");
        return;
    }       
    struct node *temp= *head;   
    while(temp->next->next!= NULL) {
        temp= temp->next;
    }
    free(temp->next);
    temp->next= NULL;
}
void DBGV(struct node **head, int pos) {
    if(*head== NULL) {
        printf("List is empty\n");
        return;
    }
    if(pos== 1) {
        struct node *temp= *head;
        *head= (*head)->next;
        free(temp);
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL || temp->next== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct node *todelete= temp->next;
    temp->next= todelete->next;
    free(todelete);
}
void DAGV(struct node **head, int pos) {
    if(*head== NULL) {
        printf("List is empty\n");
        return;
    }
    if(pos== 1) { 
        struct node *temp= *head;
        *head= (*head)->next;
        free(temp);
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL || temp->next== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct node *todelete= temp->next;
    temp->next= todelete->next;
    free(todelete);
}
void deleteAtPosition(struct node **head, int pos) {
    if(*head== NULL) {
        printf("List is empty\n");
        return;
    }
    if(pos== 1) {
        struct node *temp= *head;
        *head= (*head)->next;
        free(temp);
        return;
    }
    struct node *temp= *head;
    for(int i= 1; i< pos-1 && temp!= NULL; i++) {
        temp= temp->next;
    }
    if(temp== NULL || temp->next== NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct node *todelete= temp->next;
    temp->next= todelete->next;
    free(todelete);
}
void display(struct node *head) {
    if(head== NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp= head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main() {
    struct node *head= NULL;
    int choice, value, pos;
    while(1) {
        printf("1. Insert at front\n2. Insert at last\n3. Insert before given value\n4. Insert after given value\n5. Insert at given position\n6. Delete at front\n7. Delete at last\n8. Delete before given value\n9. Delete after given value\n10.Delete at given position\n11.Display\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                IAF(&head, value);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                IAL(&head, value);
                break;
            case 3:
                printf("Enter value to insert before given position: ");
                scanf("%d %d", &value, &pos);
                IBGV(&head, value, pos);
                break;
            case 4:
                printf("Enter value to insert after given position: ");
                scanf("%d %d", &value, &pos);
                IAGV(&head, value, pos);
                break;
            case 5:
                printf("Enter value to insert at given position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 6:         
                DAF(&head);
                break;
            case 7: 
                DAL(&head);
                break;
            case 8:
                printf("Enter position to delete at: ");
                scanf("%d", &pos);
                DBGV(&head, pos);
                break;
            case 9:
                printf("Enter position to delete after: ");
                scanf("%d", &pos);
                DAGV(&head, pos);
                break;
            case 10:
                printf("Enter position to delete at: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 11:
                display(head);
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}