#include <stdio.h>
#include <string.h>
int main() {
    int N,count=0,flag=1;
    scanf("%d",&N);
    char gem[N][100];
    for(int i=0; i<N; i++) {
        scanf("%s",gem[i]);
    }
    int freq[N][26];
    for(int i=0; i<N; i++) {
        for(int j=0; j<26; j++) {
            freq[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<strlen(gem[i]); j++) {
            freq[i][gem[i][j] - 'a']++;
        }
    }
    for(int j=0; j<26; j++)
    {
        for(int i=0; i<N; i++) {
            if(freq[i][j] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            count++;
        }
        flag = 1;
    }
    printf("%d",count);
    return 0;
}