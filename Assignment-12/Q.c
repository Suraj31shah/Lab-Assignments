#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMORY_SIZE 1024
#define MAX_PROCESSES 100

typedef struct Block {
    int size;
    int free;
    int pid;
    struct Block* next;
} Block;

Block* head=NULL;
int last_alloc=0;
int pid_counter=1;

void initialize_memory() {
    head=(Block*)malloc(sizeof(Block));
    head->size=MEMORY_SIZE;
    head->free=1;
    head->pid=-1;
    head->next=NULL;
}

void display_memory() {
    Block* temp=head;
    printf("\nMemory State:\n");
    while (temp) {
        printf("[Size: %d KB | %s | PID: %d] -> ", temp->size, temp->free ? "Free" : "Used", temp->pid);
        temp=temp->next;
    }
    printf("NULL\n");
}

void split(Block* fit, int size) {
    Block* newBlock=(Block*)malloc(sizeof(Block));
    newBlock->size=fit->size-size;
    newBlock->free=1;
    newBlock->pid=-1;
    newBlock->next=fit->next;

    fit->size=size;
    fit->free=0;
    fit->pid=pid_counter++;
    fit->next=newBlock;
}

void first_fit(int size) {
    Block* temp=head;

    while (temp) {
        if (temp->free && temp->size>=size) {
            split(temp, size);
            return;
        }
        temp=temp->next;
    }
    printf("First Fit: Allocation failed\n");
}

void next_fit(int size) {
    static Block* last=NULL;
    if (!last) {
        last=head;
    }

    Block* start=last;
    do {
        if (last->free && last->size>=size) {
            split(last, size);
            return;
        }
        last=last->next ? last->next : head;
    } while (last!=start);

    printf("Next Fit: Allocation failed\n");
}

void best_fit(int size) {
    Block *temp=head, *best=NULL;

    while (temp) {
        if (temp->free && temp->size>=size) {
            if (!best || temp->size<best->size) {
                best=temp;
            }
        }
        temp=temp->next;
    }

    if (best) {
        split(best, size);
    }
    else {
        printf("Best Fit: Allocation failed\n");
    }
}

void worst_fit(int size) {
    Block *temp=head, *worst=NULL;

    while (temp) {
        if (temp->free && temp->size>=size) {
            if (!worst || temp->size>worst->size) {
                worst=temp;
            }
        }
        temp=temp->next;
    }

    if (worst) {
        split(worst, size);
    }
    else {
        printf("Worst Fit: Allocation failed\n");
    }
}

#define QUICK_CLASSES 3
int quick_size[QUICK_CLASSES]={32, 64, 128};

void quick_fit(int size) {
    Block* temp=head;

    while (temp) {
        if (temp->free && temp->size>=size) {
            split(temp, size);
            return;
        }
        temp=temp->next;
    }
    printf("Quick Fit: Allocation failed\n");
}

void free_memory(int pid) {
    Block* temp=head;

    while (temp) {
        if(!temp->free && temp->pid==pid) {
            temp->free=1;
            temp->pid=-1;
            printf("Process is %d freed\n", pid);
            return;
        }
        temp=temp->next;
    }
    printf("PID not found\n");
}

void coalesce() {
    Block* temp=head;

    while (temp && temp->next) {
        if(temp->free && temp->next->free) {
            temp->size+=temp->next->size;
            temp->next=temp->next->next;
        }
        else  {
            temp=temp->next;
        }
    }
}

void statistics() {
    Block* temp=head;
    int used=0, free=0, fragments=0;

    while (temp) {
        if (temp->free) {
            free+=temp->size;
            fragments++;
        }
        else {
            used+=temp->size;
        }
        temp=temp->next;
    }

    printf("\nStatistics\n");
    printf("Used Memory: %d KB\n", used);
    printf("Free Memory: %d KB\n", free);
    printf("Fragments: %d\n", fragments);
    printf("Utilization: %.2f%%\n", (used*100.0)/MEMORY_SIZE);
}

int main() {
    initialize_memory();

    int choice, size, pid;

    while (1) {
        printf("\n1.First Fit\n2.Next Fit\n3.Best Fit\n4.Worst Fit\n5.Quick Fit\n6.Free\n7.Display\n8.Exit\n9.Stress Test\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size: ");
                scanf("%d", &size);
                first_fit(size);
                break;

            case 2:
                printf("Enter size: ");
                scanf("%d", &size);
                next_fit(size);
                break;

            case 3:
                printf("Enter size: ");
                scanf("%d", &size);
                best_fit(size);
                break;

            case 4:
                printf("Enter size: ");
                scanf("%d", &size);
                worst_fit(size);
                break;

            case 5:
                printf("Enter size: ");
                scanf("%d", &size);
                quick_fit(size);
                break;

            case 6:
                printf("Enter PID: ");
                scanf("%d", &pid);
                free_memory(pid);
                coalesce();
                break;

            case 7:
                display_memory();
                statistics();
                break;

            case 8:
                exit(0);
            case 9:
                for (int i=0; i<20; i++) {
                    int size=rand()%240+16;
                    printf("\nAllocating %d KB\n", size);
                    first_fit(size);
                }
                break;
        }
    }
}