#include "node.h"
#include <stdlib.h>
#include <stdio.h>

// 创建新节点
Node newNode(Key key, Value value) {
  Node node = (Node)malloc(sizeof(struct tree_node));
  node->key = key;
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void allocateTree(BST bst) {
  bst = (BST)malloc(sizeof(struct __BST));
  bst->root = NULL;
  bst->count = 0;
}

// 向以 node 为根的二叉搜索树中插入节点 node
Node __insert(BST tree, Node node, Key key, Value value) {
  if (node == NULL) {
    tree->count ++;
    return newNode(key, value);
  }

  // 如果插入的值与当前节点相等，替换值
  if (key == node->key)
    node->value = value;
  else if (key < node->left->key)
    node->left = __insert(tree, node->left, key, value);
  else 
    node->right = __insert(tree, node->right, key, value);
    printf("\n===== node: %p", node);
  return node;
}

void insert(BST tree, Key key, Value value) {
  printf("\nbefore---tree: %p", tree);
  printf("\nbefort----root: %p", tree->root);
  tree->root = __insert(tree, tree->root, key, value);
  printf("\ntree: %p", tree);
  printf("\nroot: %p", tree->root);
}

// 中序遍历节点
void __printNode(Node node) {
  if (node == NULL)
    return;

  printf("\n{%d : %d}", node->key, node->value);
  __printNode(node->left);
  __printNode(node->right);
}

// 遍历二叉搜索树
void printTree(BST bst) {
  __printNode(bst->root);
}

