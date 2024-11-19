#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d",&n);
    getchar();
    char (*c)[100] = (char (*)[100]) malloc(n * 100 * sizeof(char));
    if(c == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Maximum string size: 100\n");
    printf("Enter your strings: \n");
    for(int i=0; i<n; i++) {
        fgets(c[i],100,stdin);
        c[i][strcspn(c[i], "\n")] = '\0';
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(strcmp(c[i],c[j]) > 0)
                {
                    char *p = (char *) malloc(100 * sizeof(char));
                    strcpy(p,c[i]);
                    strcpy(c[i],c[j]);
                    strcpy(c[j],p);
                    free(p);
                }
        }
    }
    printf("Ordered Strings: \n");
    for(int i=0; i<n; i++) {
        printf("%s\n",c[i]);
    }
    free(c);
    return 0;
}