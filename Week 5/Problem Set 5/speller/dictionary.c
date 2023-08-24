// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;                      /* Each bucket is marked A-Z */

unsigned int word_count;
unsigned int hash_value;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);

    // Cursor is assigned with address of head of the linked list
    node* cursor = table[hash_value];

    // Compare till we reach the end of the linked list
    while(cursor != NULL)
    {
        // Compare the word with the word on the present node
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // Traverse through nodes in the linked list
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        total = total + tolower(word[i]);       /* sum all ASCII values of each character in the word */
    }
    return total % N;
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Read the file in dictionaries.
    FILE* file = fopen(dictionary, "r");        /* Open the file for purpose of reading and return a pointer */
    if(file == NULL)
    {
        printf("This file %s cannot be opened", dictionary);
        return false;
    }

    char word[LENGTH + 1];                      /* Strings are array of chars */

    // Read the file string by string and store each word into the char variable "word" until we reach EOF
    // fscanf(POINTER, type of data to read: %i, %d,%s, store data into this variable)
    while(fscanf(file, "%s", word) != EOF)
    {
        // Malloc-ing a node pointer for each word in hash table
        node* n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }

        // Copying words from dictionary into node
        // strcpy(destination, source)
        strcpy(n->word, word);                  /* Copy from char variable into n->word */
        hash_value = hash(word);                /* Getting index of hash table location */

        // Adding nodes into hash table without orphaning existing nodes
        n->next = table[hash_value];
        table[hash_value] = n;

        // Keeping count of words
        word_count++;
    }
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
   return (word_count > 0) ? word_count : 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to the start of the linked list
        node* cursor = table[i];

        // If coursor is not NULL, free memory
        while (cursor != NULL)
        {
            // Create temp
            node* tmp = cursor;
            // Move cursor to next node
            cursor = cursor->next;
            // Free up temp;
            free(tmp);
        }
    }
    return true;
}



