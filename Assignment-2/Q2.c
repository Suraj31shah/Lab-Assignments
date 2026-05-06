#include <stdio.h>
#include <stdlib.h>

struct data {
    int *arr1;
    int *arr2;
};
int main() {
    int n,i;
    struct data *data=(struct data*)malloc(sizeof(struct data));
    if(data==NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    data->arr1=(int*)malloc(n*sizeof(int));
    data->arr2=(int*)malloc(n*sizeof(int));
    if(data->arr1==NULL || data->arr2==NULL) {
        printf("Memory allocation failed or arrays!");
        return 1;
    }

    printf("Enter %d elements for the array:\n",n);
    for(int i=0; i<n; i++) {
        scanf("%d",(data->arr1+i));
    }

    for(int i=0; i<n; i++) {
        *(data->arr2+i)=*(data->arr1+i);
        if(i%2!=0 && i>0 && i<n-1) {
            *(data->arr2+i)=*(data->arr1+i-1) * *(data->arr1+i+1);
        }
    }

    printf("Original Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",*(data->arr1+i));
    }
    printf("\n");
    printf("Modified Array: ");
    for(int i=0; i<n; i++) {
        printf("%d ",*(data->arr2+i));
    }
    printf("\n");

    free(data->arr1);
    free(data->arr2);
    free(data);
}