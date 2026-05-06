#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct stack {
    Node* top;
} STACK;

void create(STACK **s) {
    *s = (STACK*)malloc(sizeof(STACK));
    if (*s == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*s)->top = NULL;
}

bool isEmpty(STACK *s) {
    return s->top == NULL;
}

void push(STACK **s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow. Cannot push %d\n", data);
        return;
    }
    newNode->data = data;
    newNode->next = (*s)->top;
    (*s)->top = newNode;
}

int pop(STACK **s) {
    if (isEmpty(*s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* temp = (*s)->top;
    int popped = temp->data;
    (*s)->top = (*s)->top->next;
    free(temp);
    return popped;
}

int peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return s->top->data;
}

bool isFull(STACK *s) {
    return false;
}

int main() {
    STACK *A;
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
            printf("Element %d deleted\n",pop(&A));
            break;
        case 3:
            printf("The top data element of the stack is %d",peek(A));
            break;
        case 0:
            return 0;
        
        default:
            printf("Invalid choice!\n");
        }
    }
}