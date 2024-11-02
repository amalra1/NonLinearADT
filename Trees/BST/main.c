#include <stdio.h>
#include "bst.h"

int main() 
{
    node_t* root = NULL;

    // Insert elements and print
    root = insert(root, 154);
    root = insert(root, 23);
    root = insert(root, 12);
    root = insert(root, 1);
    root = insert(root, 200);
    root = insert(root, 459);

    printf("ADDS ELEMENTS\n");
    printInOrder(root);
    printf("\n\n");

    // Remove a few elements and print
    root = delete(root, 12);

    printf("REMOVE ELEMENT: 12\n");
    printInOrder(root);
    printf("\n\n");

    root = delete(root, 23);
    root = delete(root, 200);
    root = delete(root, 154);

    printf("REMOVE ELEMENTS: 23, 200, 154\n");
    printInOrder(root);
    printf("\n\n");

    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 999);

    printf("ADDS ELEMENTS\n");
    printInOrder(root);
    printf("\n\n");

    printf("MAX ELEMENT IN THE TREE: %d\n\n", max(root));
    printf("MIN ELEMENT IN THE TREE: %d\n\n", min(root));

    printf("SEARCHING FOR: 1000\n");
    if (!find(root, 1000))
        printf("Not found!\n");
    else
        printf("Found!\n\n");

    printf("SEARCHING FOR: 10\n");
    if (!find(root, 10))
        printf("Not found!\n");
    else
        printf("Found!\n\n");
    
    destroyTree(root);
    
    return 0;
}
