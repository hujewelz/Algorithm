#include <stdio.h>
#include "tool.c"

void bubbleSort(int *arr, int n) {
  int i, j;
  for (i=1; i<n; i++) {
    char flag = 1;
    for (j=0; j<n-i; j++) {
      if (arr[j+1] < arr[j]) {
        int tmp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = tmp;
        flag = 0;
      }
    }
    if (flag) break;
  }
}

int main() {
  run(&bubbleSort);
}