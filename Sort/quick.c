#include <stdio.h>
#include "tool.c"

void __quickSort(int *arr, int low, int hight) {
  if (low >= hight) {
    return;
  }

  int i = low;
  int j = hight;
  int base = arr[low];
  while (i < j) {
    while (i < j && arr[j] >= base) {
      j -= 1;
    }
    arr[i] = arr[j];
    
    while (i < j && arr[i] < base) {
      i += 1;
    }
    arr[j] = arr[i];
  }
  arr[i] = base;
  __quickSort(arr, low, i-1);
  __quickSort(arr, i+1, hight);
}

void quickSort(int *arr, int n) {
  __quickSort(arr, 0, n-1);
}

int main() {
  run(&quickSort);
}
