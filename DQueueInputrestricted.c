#include<stdio.h>
#define SIZE 100
typedef struct {
    int Q[SIZE];
    int f;
    int r;
} DQueue;
void initQueue(DQueue *dq) {
    dq->f = -1;
    dq->r = -1;
}
void enqueue(DQueue *dq, int value) {
    if((dq->f == 0 && dq->r == SIZE - 1) || (dq->f == dq->r + 1)) {
        printf("Queue is full\n");
        
    }
    else{
        if(dq->f == -1) {
            dq->f = 0;
            dq->r = 0;
        } else if(dq->r == SIZE - 1) {
            dq->r = 0;
        } else {
            dq->r++;
        }   
        dq->Q[dq->r] = value;
    }
}

int dequeueF(DQueue *dq) {
    if(dq->f == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = dq->Q[dq->f];
    if(dq->f == dq->r) {
        dq->f = -1; 
        dq->r = -1;
    } else if(dq->f == SIZE - 1) {
        dq->f = 0;
    } else {
        dq->f++;
    }
    return value;
}
int dequeueR(DQueue *dq) {
    if(dq->f == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = dq->Q[dq->r];
    if(dq->f == dq->r) {
        dq->f = -1;
        dq->r = -1;
    } else if(dq->r == 0) {
        dq->r = SIZE - 1;
    } else {
        dq->r--;
    }
    return value;
}
void display(DQueue *dq) {
    if(dq->f == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = dq->f;
    while(1) {
        printf("%d ", dq->Q[i]);
        if(i == dq->r) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    DQueue dq;
    initQueue(&dq);
    int choice, value;
    while(1) {
        printf("1. Enqueue\n2. Dequeue from front\n3. Dequeue from rear\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&dq, value);
                break;
            case 2:
                value = dequeueF(&dq);
                if(value != -1) {
                    printf("Dequeued from front: %d\n", value);
                }
                break;
            case 3:
                value = dequeueR(&dq);
                if(value != -1) {
                    printf("Dequeued from rear: %d\n", value);
                }
                break;
            case 4:
                display(&dq);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}        

       