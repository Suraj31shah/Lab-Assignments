#include <stdio.h>

#define MAXSIZE 100
struct stack {
int stArr[MAXSIZE];
int top;
};
typedef struct stack STACK;

void create(STACK *s) {
    s->top=-1;
}

int isFull (STACK *s) {
    if (s->top==MAXSIZE-1) {
        return 1;
    }
    return 0;
}

int isEmpty (STACK *s) {
    if (s->top==-1) {
        return 1;
    }
    return 0;
}

void push (STACK *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow");
        return;
    }
    s->top++;
    s->stArr[s->top]=data;
}

int pop (STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow");
        return -1;
    }
    int x=s->stArr[s->top];
    s->top--;
    printf("Element %d deleted\n",x);
    return x;
}

void peek (STACK *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow");
        return;
    }
    printf("The top data element of the stack is %d",s->stArr[s->top]);
}

int main() {
    STACK A;
    int choice, data;
    create(&A);
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(&A, data);
            break;
        case 2:
            pop(&A);
            break;
        case 3:
            peek(&A);
            break;
        case 0:
            return 0;
        
        default:
            printf("Invalid choice!\n");
        }
    }
}