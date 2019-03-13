#include <stdio.h>
#include "tool.c"

void insertion(int *arr, int n) {
  for (int i=1; i<n; i++) {
    int j = i;
    int tmp = arr[i];
    while (j>0 && tmp < arr[j-1]) {
      arr[j] = arr[j-1];
      j--;
    }
    if (j != i) {
      arr[j] = tmp;
    }
  }
}

int main() {
  run(&insertion);
}