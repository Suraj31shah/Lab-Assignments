#include<stdio.h>
int main() {
    int arr[10],i;
    int count_even=0,count_odd=0;
    for (i=0; i<10; i++) {
        printf("Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The numbers entered are: ");
    for (i=0; i<10; i++) {
        printf("%d\t",arr[i]);
        if (arr[i]%2!=0) {
            count_odd+=1;
        }
        else {
            count_even+=1;
        }
    }
    printf("\nNumber of odd elements=%d\n",count_odd);
    printf("Number of even elements=%d",count_even);
    return 0;
}