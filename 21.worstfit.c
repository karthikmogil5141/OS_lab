#include <stdio.h>

#define MAX 100

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores block index for each process
    int i, j;

    // Initialize all allocations to -1 (indicating unallocated)
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Allocate memory to processes using Worst Fit strategy
    for (i = 0; i < n; i++) {
        int worstIdx = -1;

        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block was found
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; // Reduce the allocated block size
        }
    }

    // Display allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n, i;

    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the sizes of memory blocks: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the sizes of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Apply worst fit algorithm
    worstFit(blockSize, m, processSize, n);

    return 0;
}
