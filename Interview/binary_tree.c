#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
  int val;
  struct tree_node *left;
  struct tree_node *right;
} *TreeNode;

TreeNode create_tree() {
  char c;
  scanf("%s", &c);
  if (c == '#') {
    return NULL;
  }
  
  TreeNode node = (TreeNode)malloc(sizeof(struct tree_node));
  node->val = (int)c;
  node->left = create_tree();
  node->right = create_tree();
  return node;
}

void preorder_recursive(TreeNode root) {
  if (root == NULL) {
    return;
  }
  printf("%d, ", root->val);
  preorder_recursive(root->left);
  preorder_recursive(root->right);
}
// void preorder_traveral(TreeNode root) {
//   stack s;
//   TreeNode node = root; 
//   while(!s.empty() || node != NULL){
//     if (node != NULL) {
//       printf("%d, ", node->val);
//       s.push(node);
//       node = node->left;
//     } else {
//       node = s.pop()->right;
//     }
//   }
// }

int main() {
  TreeNode root = create_tree();
  preorder_recursive(root);
}