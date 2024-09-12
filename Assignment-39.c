#include <stdio.h>
int main()
{
    float n, a = 1, sum = 0;
    printf("Enter till which Term you want to Print ");
    scanf("%f", &n);

    for (float i = 1; i <= n; i++)
    {
        a = a * i;

        printf("+ %f/%f ", i, a);
        sum = sum + i / a;
    }
    printf("\nThe Sum is %f", sum);

    return 0;
}