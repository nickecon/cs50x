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

//global variables
int hv = 0; //hv=hashvalue
unsigned int count = 0;
node *node1 = NULL;
unsigned int a, b, c = 0;

//Choose number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash word, access linked list
    hv = hash(word);
    if (table[hv] == NULL)
    {
        return false;
    }
    node *node4 = table[hv];

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
//hash word to obtain a hash value
//access linked list at that index in the hash table
//traverse linked list, looking for the word (strcasecmp)
//traverse by set cursor to first item of linked list, keep moving until null
//if no word was found then produce false

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    a = word[0];
    b = word[1];
    c = word[2];
    a = (a > 64 && b < 91) ? a + 32 : a + 0;
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
    //opens file , checks if null
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    //read strings from file and store for hash
    while (fscanf(file, "%s", input) != EOF)
    {
        node1 = malloc(sizeof(node));
        if (node1 == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(node1->word, input);
        count++;

        //get hash value from word and insert node into array at that loc
        hv = hash(input);
        if (table[hv] == NULL)
        {
            table[hv] = node1;
            node1->next = NULL;
        }
        else
        {
            node1->next = table[hv];
            table[hv] = node1;
        }
    }
    fclose(file);
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
    return count;
}
//itterate over every linked list inside hash table , counting number of nodes
//or when loading hash table , keep track number of nodes added to later include in size function

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    hv = 0;
    node *node3 = table[hv];
    node *node2 = table[hv];
    while (node2 != NULL)
    {
        node2 = node2->next;
        free(node3);
        node3 = node2;
    }
    node1 = NULL;
    free(node1);
    return true;
}
//call free on memory that was previously malloced
//return true if done successfully
//free all nodes
//recursive function to free
//set tmp and cursor to first node
//move cursor to second node
//move tmp to second, repeat
//when cursor points to null return true