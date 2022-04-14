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
const unsigned int N = 17576;

// Important variables made global
int hv = 0;
//unsigned int hashed = 0;
node *node1 = NULL;
unsigned int a, b, c, count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash, allocate space and copy word to node
    hv = hash(word);
    if (table[hv] == NULL)
    {
        return false;
    }
    node *node4 = table[code];

    // If found, return true. If not, go next until false.
    while (node4 != NULL)
    {
        if (strcasecmp(word, node4->word) == 0)
        {
            return true;
        }
        else
        {
            node4 = node4->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // NOTE: Try manipulating the word itself
    // Initialize all int values, hash first letter and check next letter
    a = word[0];
    b = word[1];
    c = word[2];
    a = (a > 64 && a < 91) ? a + 32 : a + 0;
    a %= 97;
    if ((b > 64 && b < 91) || (b > 96 && b < 123))
    {
        b = (b > 64 && b < 91) ? b + 32 : b + 0;
        b %= 97;
        b *= 26;

        // Check if next letter can be hashed; else return x + y
        if ((c > 64 && c < 91) || (c > 96 && c < 123))
        {
            c = (c > 64 && c < 91) ? c + 32 : c + 0;
            c %= 97;
            c *= 676;
            return a + b + c;
        }
        else
        {
            return a + b;
        }
    }
    else
    {
        return a;
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