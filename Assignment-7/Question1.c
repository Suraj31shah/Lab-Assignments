#include <stdio.h>
#include <math.h>

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
    return x;
}

int evaluate(char expression[]) {
    STACK s;
    create(&s);
    int op1,op2,res;
    for (int i=0; expression[i]!='\0'; i++) {
            if (expression[i]>='0' && expression[i]<='9') {
                int num=0;
                while (expression[i]>='0' && expression[i]<='9') {
                    num=num*10+(int)expression[i++]-48;
                }
                push(&s,num);
            }
            else if (expression[i]!=' ') {
                op2=pop(&s);
                op1=pop(&s);
                switch(expression[i]) {
                    case '*':
                        res=op1*op2;
                        break;
                    case '/':
                        res=op1/op2;
                        break;
                    case '-':
                        res=op1-op2;
                        break;
                    case '+':
                        res=op1+op2;
                        break;
                    case '^':
                        res=pow(op1,op2);
                        if(op1%5==0 && op1!=0)
                        {
                            res++;
                        }
                        break;
                }
                push(&s,res);
            }
    }
    return pop(&s);
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    gets(expression);
    printf("%d",evaluate(expression));
}