#include <stdio.h>

void swap(int *arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void printArr(int *arr, int n) {
  for (int i=0; i<n; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

typedef void (*Function)(int*, int);

void run(Function func) {
  int array[] = {1, 34, 2, 32, 45, 56, 3, 5, 67, 9, 78};
  func(array, 11);
  printArr(array, 11);
}
