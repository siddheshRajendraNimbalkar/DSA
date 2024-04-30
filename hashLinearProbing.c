#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct HashNode {
    char *key;
    int value;
};

struct HashTable {
    struct HashNode table[TABLE_SIZE];
};

int hash(char *key) {
    int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

void initializeHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i].key = NULL;
        hashTable->table[i].value = -1;
    }
}

void insert(struct HashTable *hashTable, char *key, int value) {
    int index = hash(key);

    while (hashTable->table[index].key != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable->table[index].key = strdup(key); 
    hashTable->table[index].value = value;
}

int search(struct HashTable *hashTable, char *key) {
    int index = hash(key);

    while (hashTable->table[index].key != NULL) {
        if (strcmp(hashTable->table[index].key, key) == 0) {
            return hashTable->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1;
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    insert(&hashTable, "apple", 10);
    insert(&hashTable, "banana", 20);
    insert(&hashTable, "cherry", 30);
    printf("Value for 'apple': %d\n", search(&hashTable, "apple"));

    printf("Value for 'banana': %d\n", search(&hashTable, "banana"));
    printf("Value for 'cherry': %d\n", search(&hashTable, "cherry"));
    printf("Value for 'orange': %d\n", search(&hashTable, "orange"));
  
    
    return 0;
}

