#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
#define STACKSIZE 6
struct person {
    int empnr;
    char name[12];
    int age;
};
 
struct stack {
    struct person items[STACKSIZE];
    int top;
};
 
void push(struct stack *, struct person);
 
struct person pop(struct stack *);
 
void main(void) {
    struct stack s;
    struct person p;
    char optype;
s.top = -1;
    do {
        printf("Enter Operation type \n");
        scanf("\n%c", &optype);
        switch (optype) {
            case 'I': {
                printf("Enter empnr, name and age \n");
scanf("%d %s %d", &p.empnr, p.name, &p.age);
                push(&s, p);
                break;
            }
            case 'D': {
                p = pop(&s);
printf("empnr: %d, name: %s, age: %d\n", p.empnr, p.name, p.age);
                break;
            }
            default :
                printf("%s", "Illegal Operation code \n");
        }
    } while (optype != 'E');
}
 
struct person pop(struct stack *ps) {
    struct person p;
    if (ps->top == -1) {
        printf("%s", "stack underflow");
        exit(1);
    } else {
        p = ps->items[ps->top];
        ps->top = ps->top - 1;
    }
    return p;
}
 
void push(struct stack *ps, struct person p) {
    if (ps->top == STACKSIZE - 1) {
        printf("%s", "stack overflow ");
        exit(1);
    } else {
        ps->top = ps->top + 1;
        ps->items[ps->top] = p;
    }
}