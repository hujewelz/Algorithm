#include <stdio.h>

void bubbleSort(int *arr, int n) {
  int i, j;
  for (i=0; i<n-1; i++) {
    for (j=i+1; j<n-1; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int main() {
  int array[] = {1, 34, 2, 32, 45, 56, 3, 5, 67, 9, 78};
  bubbleSort(array, 11);

  for (int i=0; i<11; i++) {
    printf("%d, ", array[i]);
  }
}