#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Segment {
    int base;
    int limit;
    int allocated;
};

struct Process {
    int pid;
    struct Segment code;
    struct Segment data;
    struct Segment stack;
};

struct Process processes[MAX_PROCESSES];
int process_count=0;
int memory_pointer=1000;

void allocate_segment(struct Segment *seg, int size) {
    seg->base=memory_pointer;
    seg->limit=size;
    seg->allocated=1;
    memory_pointer+=size;
}

void create_process() {
    if (process_count>=MAX_PROCESSES) {
        printf("Process limit reached!\n");
        return;
    }

    struct Process p;
    p.pid=process_count;

    int code_size, data_size, stack_size;

    printf("\nEnter sizes for Process %d:\n", p.pid);
    printf("Code size: ");
    scanf("%d", &code_size);
    printf("Data size: ");
    scanf("%d", &data_size);
    printf("Stack size: ");
    scanf("%d", &stack_size);

    allocate_segment(&p.code, code_size);
    allocate_segment(&p.data, data_size);
    allocate_segment(&p.stack, stack_size);

    processes[process_count++]=p;

    printf("Process %d allocated successfully");
}

void delete_process() {
    int pid;
    printf("Enter process ID to delete: ");
    scanf("%d", &pid);

    if (pid<0 || pid>=process_count) {
        printf("Invalid PID!\n");
        return;
    }

    processes[pid].code.allocated=0;
    processes[pid].data.allocated=0;
    processes[pid].stack.allocated=0;

    printf("Process %d deallocated!\n", pid);
}

void display() {
    printf("\nProcess Table\n");

    for(int i=0; i<process_count; i++) {
        struct Process p=processes[i];

        printf("\nProcess %d:\n", p.pid);

        printf("Code  -> Base: %d, Limit: %d, %s\n", p.code.base, p.code.limit, p.code.allocated ? "Allocated" : "Free");

        printf("Data  -> Base: %d, Limit: %d, %s\n", p.data.base, p.data.limit, p.data.allocated ? "Allocated" : "Free");

        printf("Stack -> Base: %d, Limit: %d, %s\n", p.stack.base, p.stack.limit, p.stack.allocated ? "Allocated" : "Free");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Create Process\n2. Delete Process\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_process();
                break;
            case 2:
                delete_process();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}