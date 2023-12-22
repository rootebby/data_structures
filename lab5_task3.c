#include<stdio.h>
#include<stdlib.h>

#define MAXELEMENTS 5
#define TRUE 1
#define FALSE 0

// Circular Queue structure
struct queue {
    int items[MAXELEMENTS];
    int front, rear;
};

// Function prototypes
void cqinsert(struct queue *, int);
int cqdelete(struct queue *);
int empty(struct queue *);
void display(struct queue *);

int main(void) {
    char operation;
    int x;
    struct queue q;
    q.front = q.rear = MAXELEMENTS - 1;

    do {
        printf("%s\n", "Insert Operation type I D or E ");
        scanf("\n%c", &operation);

        switch (operation) {
            case 'I':
                printf("%s\n", "Insert an element");
                scanf("\n%d", &x);
                cqinsert(&q, x);
                break;
            case 'D':
                x = cqdelete(&q);
                printf("\n %d is deleted \n", x);
                break;
        }

        // Display current state of the circular queue
        display(&q);
    } while (operation != 'E');

    return 0;
}

int empty(struct queue *pq) {
    return ((pq->front == pq->rear) ? TRUE : FALSE);
}

int cqdelete(struct queue *pq) {
    if (empty(pq)) {
        printf("Queue underflow ");
        exit(1);
    }

    int deletedValue = pq->items[pq->front];

    if (pq->front == MAXELEMENTS - 1)
        pq->front = 0;
    else
        (pq->front)++;

    return deletedValue;
}

void cqinsert(struct queue *pq, int x) {
    // Make room for the new element
    if (pq->rear == MAXELEMENTS - 1)
        pq->rear = 0;
    else
        (pq->rear)++;

    if (pq->rear == pq->front) {
        printf("Queue overflow");
        getchar();
        getchar();
        exit(1);
    }

    printf("\n %d is inserted at location %d\n", x, pq->rear);
    pq->items[pq->rear] = x;
}

void display(struct queue *pq) {
    printf("Front: %d, Rear: %d\n", pq->front, pq->rear);
    printf("Circular Queue: ");
    int i = pq->front;
    do {
        i = (i + 1) % MAXELEMENTS;
        printf("%d ", pq->items[i]);
    } while (i != pq->rear);
    printf("\n");
}
