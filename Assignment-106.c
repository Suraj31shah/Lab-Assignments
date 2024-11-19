#include <stdio.h>
struct item{
    char item_name[100];
    int quantity;
    float price;
    float amount;
};
void calc_amount(int n,struct item arr[n]) {
    for (int i=0; i<n; i++) {
        arr[i].amount=arr[i].quantity*arr[i].price;
    }
    for (int i=0; i<n; i++) {
        printf("Amount of %s is %f\n",arr[i].item_name,arr[i].amount);
    }
}
int main() {
    int n,i;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    struct item arr[n];
    for (i=0; i<n; i++) {
        printf("Enter item name: ");
        scanf("%s",&arr[i].item_name);
        printf("Enter quantity: ");
        scanf("%d",&arr[i].quantity);
        printf("Enter price: ");
        scanf("%f",&arr[i].price);
    }
    calc_amount(n, arr);
}