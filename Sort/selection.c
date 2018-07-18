#include <stdio.h>
#include "tool.c"

void selection(int *arr, int n) {
  for (int i=0; i<n-1; i++) {
    int min = i;
    for (int j=i+1; j<n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }

      if (i != min) {
        swap(arr, j, min);
      }
    }
  }
}

int main() {
  run(&selection);
  return 1;
}