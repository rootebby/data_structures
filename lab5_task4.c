#include <stdio.h>
#include <string.h>

struct person {
    int empNo;
    char name[12];
    int age;
    char gender[2]; /* M=male, F=Female */
};

struct queue {
    struct person allperson[15];
    int front, rear;
};

void initializeQueue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isQueueFull(struct queue *q) {
    return ((q->rear + 1) % 15 == q->front);
}

void enqueue(struct queue *q, struct person emp) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isQueueEmpty(q)) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % 15;
        }

        q->allperson[q->rear] = emp;
    }
}

struct person dequeue(struct queue *q) {
    struct person emp;
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        emp.empNo = -1; // Return a dummy value indicating an error
    } else {
        emp = q->allperson[q->front];

        if (q->front == q->rear) {
            initializeQueue(q);
        } else {
            q->front = (q->front + 1) % 15;
        }
    }
    return emp;
}

void displayQueue(struct queue *q, const char *queueType) {
    printf("Contents of %s queue:\n", queueType);
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i = q->front;
        do {
            printf("EmpNo: %d, Name: %s, Age: %d, Gender: %s\n", 
                   q->allperson[i].empNo, q->allperson[i].name, 
                   q->allperson[i].age, q->allperson[i].gender);
            i = (i + 1) % 15;
        } while (i != (q->rear + 1) % 15);
    }
    printf("\n");
}

int main() {
    struct person tenPerson[10] = {
        {123, "Ahmet", 21, "M"},
        {234, "Sevgi", 26, "F"},
        {128, "Osman", 18, "M"},
        {432, "Mert", 27, "M"},
        {287, "Ayse", 34, "F"},
        {423, "Kemal", 21, "M"},
        {634, "Lale", 16, "F"},
        {828, "Sefer", 15, "M"},
        {252, "Meral", 27, "F"},
        {887, "Demet", 34, "F"}
    };

    struct queue mainQueue, maleQueue, femaleQueue;
    initializeQueue(&mainQueue);
    initializeQueue(&maleQueue);
    initializeQueue(&femaleQueue);

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Create a Circular queue using tenPerson array\n");
        printf("2. Delete all elements from the queue\n");
        printf("3. Create Male and Female queues\n");
        printf("4. Display Male and Female queues\n");
        printf("5. End of operation\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < 10; ++i) {
                    enqueue(&mainQueue, tenPerson[i]);
                }
                printf("Circular queue created.\n");
                break;

            case 2:
                printf("Deleted elements from the queue:\n");
                while (!isQueueEmpty(&mainQueue)) {
                    struct person emp = dequeue(&mainQueue);
                    printf("EmpNo: %d, Name: %s, Age: %d, Gender: %s\n", 
                           emp.empNo, emp.name, emp.age, emp.gender);
                    if (strcmp(emp.gender, "M") == 0) {
                        enqueue(&maleQueue, emp);
                    } else if (strcmp(emp.gender, "F") == 0) {
                        enqueue(&femaleQueue, emp);
                    }
                }
                break;

            case 3:
                printf("Male and Female queues created.\n");
                break;

            case 4:
                displayQueue(&maleQueue, "Male");
                displayQueue(&femaleQueue, "Female");
                break;

            case 5:
                printf("End of operation.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
