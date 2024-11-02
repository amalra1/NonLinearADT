#ifndef BST
#define BST
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
} node_t;

// Creates a tree node and returns it
node_t* createNode(int key);

// Returns the height of the tree
int height(node_t* node); 

// Checks if the tree is empty, returns 1 if it is and 0 otherwise
int isEmpty(node_t* node);

// Inserts the given key into the tree, returns the modified tree root if succeeded and NULL if failed
node_t* insert(node_t* node, int key); 

// Searches for a given key in the tree, returns its node if succeeded and NULL if failed
node_t* find(node_t* node, int key);

// Finds the given element, deletes it and reorders the tree, returns the modified tree node if succeeded
node_t* delete(node_t* node, int key);

// Returns the maximum value key stored inside the tree
int max(node_t* node);

// Returns the minimum value key stored inside the tree
int min(node_t* node);

// Prints the tree with Pre-Order traversal
void printPreOrder(node_t* node);

// Prints the tree with In-Order traversal
void printInOrder(node_t* node);

// Prints the tree with Post-Order traversal
void printPostOrder(node_t* node);

// Free allocated memory
void destroyTree(node_t* node); 

#endif
