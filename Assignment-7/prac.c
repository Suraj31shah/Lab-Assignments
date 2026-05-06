#include <stdio.h>

struct S {
    int A;     // 4 bytes
    char B;    // 1 byte
    char C;    // 1 byte
    char D;    // 1 byte
    float *p;  // 4 bytes (pointer on 32-bit system)
};
int main() {
    struct S s;
    float *p;
    printf("%d",sizeof(p));
}