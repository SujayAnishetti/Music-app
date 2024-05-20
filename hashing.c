#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash table size
#define HASH_TABLE_SIZE 1000

// Structure to represent a linked list node for handling hash collisions
struct HashNode {
    char word[500];
    struct HashNode* next;
};





// Hash Function
unsigned int hashFunction(const char* word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash * 31) + *word;
        word++;
    }
    return hash % HASH_TABLE_SIZE;
}




// Function to insert a word into the hash table
void insertWord(struct HashNode* hashTable[], const char* word) {
    unsigned int index = hashFunction(word);

    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Handle hash collisions using linked list
        struct HashNode* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}




// Function to search for a word in the hash table
int searchWord(struct HashNode* hashTable[], const char* word) {
    unsigned int index = hashFunction(word);

    struct HashNode* temp = hashTable[index];
    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            return 1; // Word found in the hash table 
        }
        temp = temp->next;
    }

    return 0; // Word not found in the hash table
}





int main() {
    // Create the hash table to store the dictionary
    struct HashNode* hashTable[HASH_TABLE_SIZE] = { NULL };

    // Read the dictionary of valid words and insert them into the hash table
    FILE* dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Dictionary File not found\n");
        return 1;
    }
    char word[500];
    while (fscanf(dictionaryFile, "%s", word) != EOF) {
        insertWord(hashTable, word);
    }
    fclose(dictionaryFile);

    // Ask the user to enter the text to spell-check
    printf("Enter the text to spell-check:\n");
    fgets(word, sizeof(word), stdin);

    printf("Misspelled words are:\n");

    int foundMisspelledWord = 0; // Count of mispelled words

    char* token = strtok(word, " \n");
    while (token != NULL) {

        if (!searchWord(hashTable, token)) {
            printf("%s\n", token);
            foundMisspelledWord = 1;
        }
        token = strtok(NULL, " \n");
    }

    if (!foundMisspelledWord) {
        printf("No misspelled words\n");
    }

    // Free allocated memory for the hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct HashNode* temp = hashTable[i];
        while (temp != NULL) {
            struct HashNode* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}-