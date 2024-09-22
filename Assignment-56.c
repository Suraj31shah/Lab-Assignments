#include<stdio.h>
int main() {
    int arr[10],i;
    int count_pos=0,count_neg=0,count_zero=0;
    for (i=0; i<10; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The entered numbers are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr[i]);
        if (arr[i]>0) {
            count_pos+=1;
        }
        else if(arr[i]<0) {
            count_neg+=1;
        }
        else {
            count_zero+=1;
        }
    }
    printf("\nNumber of positive elements=%d\n",count_pos);
    printf("Number of negative elements=%d\n",count_neg);
    printf("Number of zero elements=%d",count_zero);
    return 0;
}