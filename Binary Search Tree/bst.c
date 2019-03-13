#include "node.c"

int main() {
  BST bst;
  allocateTree(bst);
  insert(bst, 1, 1);
  // insert (bst, 2, 2);
  // insert(bst, 3, 3);
  printTree(bst);


  return 1;
}