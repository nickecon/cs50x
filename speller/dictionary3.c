// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
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

// Choose number of buckets in hash table
const unsigned int max = 17576;

// Important variables made global
int code = 0;
unsigned int hashed = 0;
node *ptr1 = NULL;
unsigned int x, y, z, s = 0;

// Hash table
node *table[max];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash, allocate space and copy word to node
    code = hash(word);
    if (table[code] == NULL)
    {
        return false;
    }
    node *ptr4 = table[code];

    // If found, return true. If not, go next until false.
    while (ptr4 != NULL)
    {
        if (strcasecmp(word, ptr4->word) == 0)
        {
            return true;
        }
        else
        {
            ptr4 = ptr4->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // NOTE: Try manipulating the word itself
    // Initialize all int values, hash first letter and check next letter
    x = word[0];
    y = word[1];
    z = word[2];
    x = (x > 64 && x < 91) ? x + 32 : x + 0;
    x %= 97;
    if ((y > 64 && y < 91) || (y > 96 && y < 123))
    {
        y = (y > 64 && y < 91) ? y + 32 : y + 0;
        y %= 97;
        y *= 26;

        // Check if next letter can be hashed; else return x + y
        if ((z > 64 && z < 91) || (z > 96 && z < 123))
        {
            z = (z > 64 && z < 91) ? z + 32 : z + 0;
            z %= 97;
            z *= 676;
            return x + y + z;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return x;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens file and initializes a variable
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char input[LENGTH + 1];

    // Read strings from file to take the word for hashing
    while (fscanf(file, "%s", input) != EOF)
    {
        ptr1 = malloc(sizeof(node));
        if (ptr1 == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(ptr1->word, input);
        s++;

        // Hash the word to obtain a hash value and insert node into table at that location
        code = hash(input);
        if (table[code] == NULL)
        {
            table[code] = ptr1;
            ptr1->next = NULL;
        }
        else
        {
            ptr1->next = table[code];
            table[code] = ptr1;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return s;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    code = 0;
    node *ptr3 = table[code];
    node *ptr2 = table[code];
    while (ptr2 != NULL)
    {
        ptr2 = ptr2->next;
        free(ptr3);
        ptr3 = ptr2;
    }
    ptr1 = NULL;
    free(ptr1);
    return true;
}