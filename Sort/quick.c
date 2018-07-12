#include <stdio.h>

void printArr(int *arr, int len) {
  for (int i=0; i<len; i++) {
    printf("%d, ", arr[i]);
  } 
}

void quickSort(int *arr, int low, int hight) {
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
  quickSort(arr, low, i-1);
  quickSort(arr, i+1, hight);
}

int main() {
  int array[] = {100, 34, 2, 32, 45, 56, 3, 5, 67, 9, 78};
  quickSort(array, 0, 10);
  printArr(array, 11);
}
