#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 50

typedef struct {
    int id;
    char data[RECORD_SIZE];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} SequentialFile;

void initializeFile(SequentialFile *file) {
    file->count = 0;
}

void addRecord(SequentialFile *file, int id, char *data) {
    if (file->count < MAX_RECORDS) {
        file->records[file->count].id = id;
        strncpy(file->records[file->count].data, data, RECORD_SIZE);
        file->count++;
        printf("Record added successfully.\n");
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}

void readSequential(SequentialFile *file) {
    printf("Reading records sequentially:\n");
    for (int i = 0; i < file->count; i++) {
        printf("Record %d: ID=%d, Data=%s\n", i + 1, file->records[i].id, file->records[i].data);
    }
}

void searchRecord(SequentialFile *file, int searchId) {
    printf("Searching for Record with ID %d:\n", searchId);
    for (int i = 0; i < file->count; i++) {
        if (file->records[i].id == searchId) {
            printf("Record found at position %d: Data=%s\n", i + 1, file->records[i].data);
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    SequentialFile file;
    initializeFile(&file);

    addRecord(&file, 1, "First Record");
    addRecord(&file, 2, "Second Record");
    addRecord(&file, 3, "Third Record");

    readSequential(&file);

    searchRecord(&file, 2);
    searchRecord(&file, 5);

    return 0;
}
