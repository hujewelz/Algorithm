#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* createNode(int val) {
  struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = NULL;
  return node;
}

void printNode(struct ListNode* head) {
  struct ListNode* h = head;
  while (h != NULL) {
    printf("%d, ", h->val);
    h = h->next;
  }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    for (int i=0; i<n; i++) {
      if (fast != NULL) {
        fast = fast->next;
      } else {
        break;
      }
    }
    if (fast != NULL) {
        fast = fast->next;
        printf("fast: %d\n", fast->val);
    } else {
      // head = head->next;
      // printf("new header: %d", head->val);
      return head->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return head;
}

int main() {
  struct ListNode* head = createNode(1);
  struct ListNode *node = head;
  for (int i=2; i<=5; i++) {
    node->next = createNode(i);
    node = node->next;
  }
  printNode(head);
  printf("\n============ after ==========\n");
  struct ListNode* newHeader = removeNthFromEnd(head, 5);
  printNode(newHeader);

  return 0;
}