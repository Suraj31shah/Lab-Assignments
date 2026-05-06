#include <stdio.h>

struct Segment {
    int base;
    int limit;
};

int main() {
    int n;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    struct Segment segTable[n];

    printf("\nEnter base and limit for each segment:\n");
    for(int i=0; i<n; i++) {
        printf("Segment %d:\n", i);
        printf("Base: ");
        scanf("%d", &segTable[i].base);
        printf("Limit: ");
        scanf("%d", &segTable[i].limit);
    }

    int seg_no, offset;

    printf("\nEnter logical address:\n");
    printf("Segment number: ");
    scanf("%d", &seg_no);

    printf("Offset: ");
    scanf("%d", &offset);

    if(seg_no<0 || seg_no>=n) {
        printf("\nInvalid Segment Number!\n");
    }
    else if(offset>=segTable[seg_no].limit) {
        printf("\nSegmentation Fault! Offset exceeds limit.\n");
    }
    else {
        int physical_address=segTable[seg_no].base+offset;
        printf("\nPhysical Address=%d\n", physical_address);
    }

    return 0;
}