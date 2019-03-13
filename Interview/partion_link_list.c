#include <stdio.h>
#include <stdlib.h>

/*
* 给出一个链表和一个值 x，要求将比 x 小的放到左边，大的放到右边。
*/

typedef struct link_list {
  int val;
  struct link_list *next;
} *LinkList;

LinkList linklist_from_arr(int *arr, int len) {
  LinkList head = NULL, node = head;

  for (int i = 0; i < len; ++i) {
    LinkList tmp = (LinkList)malloc(sizeof(struct link_list));
    tmp->val = arr[i];
    tmp->next = NULL;
    if (i == 0) head = tmp;
    else node->next = tmp;
    node = tmp;
  }
  return head;
}

void print_list(const LinkList head) {
  LinkList node = head;
  while (node != NULL) {
    printf("%d, ", node->val);
    node = node->next;
  }
  printf("\n");
}

LinkList emptyList() {
  LinkList list = (LinkList)malloc(sizeof(struct link_list));
  list->val = 0;
  list->next = NULL;
  return list;
}

LinkList partition_list(LinkList head, int key) {
  LinkList dummy = emptyList(), postDummy = emptyList();
  LinkList prev = dummy, post = postDummy;
  LinkList node = head;
  while(node != NULL){
    if (node->val < key) {
      prev->next = node;
      prev = node;
    } else {
      post->next = node;
      post = node;
    }
    node = node->next;
  }
  post->next = NULL;
  prev->next = postDummy->next;
  return dummy->next;
}

int main() {
  int arr[] = {1, 5, 3, 2, 4, 2};
  LinkList head = linklist_from_arr(arr, 6);
  LinkList new_head = partition_list(head, 3); 
  print_list(new_head);
  return 0;
}