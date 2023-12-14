#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

typedef struct {
    float items[SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, float value) {
    if (s->top < SIZE - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack Overflow :-)\n");
        exit(EXIT_FAILURE);
    }
}

float pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

float evaluate_postfix(char *expression) {
    Stack stack;
    initialize(&stack);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atof(token));
        } else {
            float operand2 = pop(&stack);
            float operand1 = pop(&stack);

            switch (token[0]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '$':
                    push(&stack, pow(operand1, operand2));
                    break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expression_a[] = "9 1 4 2 / + - 2 3 * /";
    float result_a = evaluate_postfix(expression_a);
    printf("Result for expression a: %.2f\n", result_a);

    char expression_b[] = "3 9 2 3 $ - * 6 +";
    float result_b = evaluate_postfix(expression_b);
    printf("Result for expression b: %.2f\n", result_b);

    return 0;
}
