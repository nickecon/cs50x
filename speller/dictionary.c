// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if ()
    return false;
}
//hash word to obtain a hash value
//access linked list at that index in the hash table
//traverse linked list, looking for the word (strcasecmp)
//traverse by set cursor to first item of linked list, keep moving until null
//if no word was found then produce false

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}
//itterate over every linked list inside hash table , counting number of nodes
//or when loading hash table , keep track number of nodes added to later include in size function

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
//call free on memory that was previously malloced
//return true if done successfully
//free all nodes
//recursive function to free
//