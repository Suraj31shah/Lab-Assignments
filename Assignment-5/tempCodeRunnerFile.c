#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal( struct node *ptr)
{
    // ptr = ( struct )malloc( sizeof(struct node));
    while (ptr != NULL)
    {
        printf("Stack Element: %d\n",ptr->data);
        ptr = ptr->next ;
    }
}

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty( struct node* top){
    if ( top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull( struct node* top){

    struct node *n = (struct node*)malloc(sizeof(struct node)) ;

    if ( n == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct node* top , int x)
{
    struct node *n = (struct node*)malloc(sizeof(struct node)) ;

    if ( isFull( top )){
        printf("Stack is OverFlow\n");
    }
    else{
        struct node *n = (struct node*)malloc(sizeof(struct node)) ;

        n->data = x ;
        n->next = top ;
        top = n ;
        return top;
    }
}
int pop( struct node **top)
{
    if(isEmpty(*top)){
        printf("Stack is overflow");
    }
    else{
        struct node *n = *top ;
        *top = (*top)->next ;
        int x = n->data ;
        free(n);
        return x;
    }
}

int main()
{
   struct node *top = NULL;

   int n,a;
   
    printf("Enter The Number Element: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {   
        scanf("%d",&a);
        top = push(top,a);
    }
    
    printf("\n");
     

    int popelement = pop(&top) ;
    printf("Popped Element is %d\n",popelement);
    linkedlisttraversal(top);

    return 0;
}

