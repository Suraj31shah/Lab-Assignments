#include <stdio.h>
#include <string.h>

void big(char c[]){
    int len = strlen(c);
    int i = len-2;
    while(c[i] >= c[i+1]) {
        i--;
    }
    if(i == -1) {
        printf("No Answer\n");
        return;
    }
    int j = len-1;
    while(c[j] <= c[i]) {
        j--;
    }
    char temp = c[i];
    c[i] = c[j];
    c[j] = temp;

    for(int k = i+1; k<len-1; k++) {
        for(int l = k+1; l<len; l++) {
            if(c[k] > c[l]) {
                char var = c[k];
                c[k] = c[l];
                c[l] = var;
            }
        }
    }
    printf("%s\n",c);
}
    int main() {
    int n;
    scanf("%d",&n);
    char a[n][101];
    for(int i=0;i<n;i++) {
        scanf("%s",a[i]);
    }
    for(int i=0; i<n;i++) {
        big(a[i]);
    }
    return 0;
}