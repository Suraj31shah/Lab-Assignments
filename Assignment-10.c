#include<stdio.h>
int main()
{
    int m,p,c,e;
    float cm;
    printf("Enter marks obtained in mathematics out of 200: ");
    scanf("%d",&m);
    printf("Enter marks obtained in physics out of 200: ");
    scanf("%d",&p);
    printf("Enter marks obtained in chemistry out of 200: ");
    scanf("%d",&c);
    printf("Enter marks obtained in entrance examination out of 100: ");
    scanf("%d",&e);
    cm=m/2+p/2+c/2+e;
    printf("Cutoff mark=%f",cm);
}

