#include<stdio.h>
int main() {
    float sales,commission;
    printf("Enter the sales amount: ");
    scanf("%f",&sales);
    if (sales<=500) {
        commission=sales*0.05;
    }
    else if (sales>500 && sales<=2000) {
        commission=35+(sales-500)*0.1;
    }
    else if (sales>2000 && sales<=5000) {
        commission=185+(sales-2000)*0.12;
    }
    else {
        commission=sales*1.25;
    }
    printf("The commission for the sales representative is Rs.%d",commission);
    return 0;
}