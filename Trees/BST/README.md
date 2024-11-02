# BINARY SEARCH TREE  

A Binary Search Tree (BST) follows a simple rule that involves the root node and its children. When you want to insert a new value into the tree, you have to verify if it is lesser or equal to the root or greater, if the first case is true, then go down through the left child of the root, if the second case is true, go down the right child. Repeat the proccess until you find an empty node, that's where the inserted element belongs.  

That way, if we traverse the tree using the **inOrder** way (*root, left-child, right-child*), the elements returned are ordened from lesser to greater.  

## APPLICATIONS  

- Sort a large dataset and ease the insertion of new elements.  
- Variations of the BST are used in Database indexing.  
