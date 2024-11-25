#include <stdio.h>
int main() {
    enum color {Red, Green, Yellow, Blue};
    enum color my_color;
    printf("Enter a colour: \n");
    printf("0. Red\n1. Green\n2. Yellow\n3. Blue\n");
    scanf("%d",&my_color);
    printf("The hexadeximal code for the colour entered is:\n");
    switch (my_color) {
        case Red:
        printf("#FF0000");
        break;
        case Green:
        printf("#00FF00");
        break;
        case Yellow:
        printf("#FFFF00");
        break;
        case Blue:
        printf("#CCEEFF");
        break;
        default:
        printf("Invalid color");
        break;
    }
}