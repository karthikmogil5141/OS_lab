#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10
#define BLOCK_SIZE 50

typedef struct {
    int blockIndex;
    char data[BLOCK_SIZE];
} FileBlock;

typedef struct {
    int indexBlock[MAX_BLOCKS];
    FileBlock *blocks[MAX_BLOCKS];
    int blockCount;
} IndexedFile;

void initializeFile(IndexedFile *file) {
    file->blockCount = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        file->indexBlock[i] = -1;
        file->blocks[i] = NULL;
    }
}

void addBlock(IndexedFile *file, int index, char *data) {
    if (file->blockCount < MAX_BLOCKS) {
        file->indexBlock[file->blockCount] = index;
        file->blocks[file->blockCount] = (FileBlock *)malloc(sizeof(FileBlock));
        file->blocks[file->blockCount]->blockIndex = index;
        snprintf(file->blocks[file->blockCount]->data, BLOCK_SIZE, "%s", data);
        file->blockCount++;
        printf("Block added successfully at index %d.\n", index);
    } else {
        printf("File is full. Cannot add more blocks.\n");
    }
}

void readIndexedFile(IndexedFile *file) {
    printf("Reading file using index block:\n");
    for (int i = 0; i < file->blockCount; i++) {
        if (file->blocks[i] != NULL)
            printf("Block %d: Index=%d, Data=%s\n", i + 1, file->blocks[i]->blockIndex, file->blocks[i]->data);
    }
}

void searchBlock(IndexedFile *file, int searchIndex) {
    printf("Searching for Block with Index %d:\n", searchIndex);
    for (int i = 0; i < file->blockCount; i++) {
        if (file->blocks[i] != NULL && file->blocks[i]->blockIndex == searchIndex) {
            printf("Block found at position %d: Data=%s\n", i + 1, file->blocks[i]->data);
            return;
        }
    }
    printf("Block not found.\n");
}

void freeFile(IndexedFile *file) {
    for (int i = 0; i < file->blockCount; i++) {
        if (file->blocks[i] != NULL) {
            free(file->blocks[i]);
            file->blocks[i] = NULL;
        }
    }
}

int main() {
    IndexedFile file;
    initializeFile(&file);

    addBlock(&file, 1, "First Block");
    addBlock(&file, 2, "Second Block");
    addBlock(&file, 3, "Third Block");

    readIndexedFile(&file);

    searchBlock(&file, 2);
    searchBlock(&file, 5);

    freeFile(&file);
    return 0;
}
