// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//global numbers
unsigned int count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //TODO
    //
    if (hash(*word) ==  )
    {
        return true;
    }
    else
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
    return toupper(word[0] + word[1] + word[2]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Unable to load dictionary\n");
        return false;
    }

    //read string from file one line at a time
    char word[LENGTH + 1];

    for (i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        //abort protocol
        if (n == NULL)
        {
            unload();
            return false;
        }
        //create new node for each word
        strcpy(n->word, word);
        n->next = NULL;
        count++;
        char *c = n->word;
        int number = hash(c);
        
        }
    }
    return true;
}
//Open dictionary file - use fopen, remember to check if return is NULL
//read strings from file one at a time - use fscanf(file, %s, word) ,
//  return EOF once it hits EOF,use loop to run fscanf until EOF
//create a new node for each word - use malloc, check for NULL,
//  copy word into node using strcpy, copies string from one loc to other
//hash word to obtain a hash value - takes string and returns index
//insert node into hash table at that location -
//  set new node to first node, set head to new node

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
//set tmp and cursor to first node
//move cursor to second node
//move tmp to second, repeat
//when cursor points to null return true