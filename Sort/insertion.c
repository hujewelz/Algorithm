#include <stdio.h>
#include "tool.c"

void insertion(int *arr, int n) {
  for (int i=1; i<n; i++) {
    int j = i;
    while (j>0 && arr[j] < arr[j-1]) {
      swap(arr, j, j-1);
      j--;
    }
  }
}

int main() {
  run(&insertion);
}