#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int n=100,num_of_guess=0;
    int num,guess;
    srand(time(NULL));
    num=rand() % n;
    printf("Guess a number between '1' and '100': \n" );
    do {
        if (num_of_guess>9) {
            printf("\nYou Loose!\n");
            break;
        }
        scanf("%d",&guess);
        if (guess>num) {
            printf("Lower number please!\n");
            num_of_guess++;
        }
        else if (num>guess) {
            printf("Higher number please!\n");
            num_of_guess++;
        }
        else {
            printf("You guessed the number in %d attempts!\n",num_of_guess);
        }
    } while (guess!=num);
    return 0;
}