#include <stdio.h>

typedef int Key;
typedef int Value;

struct tree_node {
  Key key;
  Value value;
  struct tree_node *left;
  struct tree_node *right;
};

typedef struct tree_node *Node;
 
typedef struct __BST {
  struct tree_node *root;
  int count;

} *BST;

Node newNode(Key, Value);

void allocateTree(BST);

// int isTreeEmpty(const BST);

void insert(BST, Key, Value);

void printTree(BST);