#include <stdio.h>

#define MAX_SEGMENTS 10

struct Segment {
    int base;
    int limit;
};

int main() {
    struct Segment segTable[MAX_SEGMENTS];
    int n, i;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    printf("Enter base and limit for each segment:\n");
    for (i=0; i<n; i++) {
        printf("Segment %d:\n", i);
        printf("Base: ");
        scanf("%d", &segTable[i].base);
        printf("Limit: ");
        scanf("%d", &segTable[i].limit);
    }

    int seg_no, offset;

    while (1) {
        printf("\n Enter segment number (-1 to exit): ");
        scanf("%d", &seg_no);

        if (seg_no==-1) {
            break;
        }

        printf("Enter offset: ");
        scanf("%d", &offset);
        
        if (seg_no>=n || seg_no<0) {
            printf("Invalid segment number!\n");
            continue;
        }

        if (offset>=segTable[seg_no].limit) {
            printf("Segmentation Fault! Offset exceeds limit.\n");
        }
        else {
            int physical_address=segTable[seg_no].base+offset;
            printf("Physical Address=%d\n", physical_address);
        }
    }
    return 0;
}