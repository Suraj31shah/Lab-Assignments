#include<stdio.h>
int main() {
    float power_usage,rate;
    printf("Enter the power consumption in unit: ");
    scanf("%f",&power_usage);
    if (power_usage>=0 && power_usage<=200) {
        rate=power_usage*0.5;
    }
    else if (power_usage>200 && power_usage<=400) {
        rate=100+(power_usage-200)*0.65;
    }
    else if (power_usage>400 && power_usage<=600) {
        rate=230+(power_usage-400)*0.8;
    }
    else {
        rate=425+(power_usage-600)*125;
    }
    printf("The customer has to pay Rs.%f",rate);
    return 0;
}