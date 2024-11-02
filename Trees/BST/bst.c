#include "bst.h"

node_t* createNode(int key)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(node_t* node) 
{
    if (node == NULL)
        return -1;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int isEmpty(node_t* node)
{
    if (!node)
        return 1;
    return 0;
}

node_t* insert(node_t* node, int key) 
{ 
    if (isEmpty(node))
        return createNode(key);
    
    // To deal with duplicates, if it is already in the tree it just
    // returns the node where it was found
    if (key == node->key)
        return node;
    
    // Go down in the tree
    if (key > node->key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);

    return node;
}

node_t* find(node_t* node, int key)
{   
    if (isEmpty(node) || key == node->key)
        return node;

    if (key > node->key)
        return find(node->right, key);
    else
        return find(node->left, key);
}

// Gets the successor of the given node, basically 
// goes all the way down left after taking the right child first
node_t* getSuccessor(node_t* node)
{
    node = node->right;

    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;  
}

node_t* delete(node_t* node, int key)
{
    if (node == NULL)
        return node;
    
    // Finds the node to be deleted
    if (key > node->key)
        node->right = delete(node->right, key);
    else if (key < node->key)
        node->left = delete(node->left, key);
    // Found
    else 
    {
        // Case 1 - Right child only or no child at all
        if (node->left == NULL)
        {
            node_t* temp = node->right;
            free(node);
            return temp;
        }

        // Case 2 - Left child only
        if (node->right == NULL)
        {
            node_t* temp = node->left;
            free(node);
            return temp;
        }

        // Case 3 - Both childs
        node_t* successor = getSuccessor(node);

        // Trade node to be deleted with successor and deletes the node
        node->key = successor->key;
        node->right = delete(node->right, successor->key);
    }

    return node;
}

int max(node_t* node)
{
    while (node != NULL && node->right != NULL)
        node = node->right;
    return node->key;  
}

int min(node_t* node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node->key;  
}

void printPreOrder(node_t* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->key);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(node_t* node)
{
    if (node == NULL)
        return;

    printInOrder(node->left);
    printf("%d ", node->key);
    printInOrder(node->right);
}

void printPostOrder(node_t* node)
{
    if (node == NULL)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->key);
}

void destroyTree(node_t* node) 
{
    if (node == NULL)
        return;

    destroyTree(node->left);
    destroyTree(node->right);

    free(node);
}
