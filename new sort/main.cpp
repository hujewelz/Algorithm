#include <iostream>
#include "sorthelper.hpp"

int main() {

  int n = 10000;
  int *arr = sort::randomArr<int>(n);
  int *arr2 = sort::copyedArr(arr, n);
  int *arr3 = sort::copyedArr(arr, n);
  int *arr4 = sort::copyedArr(arr, n);
  int *arr5 = sort::copyedArr(arr, n);
  
  sort::testSort("冒泡排序", bubbleSort, arr, n);
  sort::testSort("插入排序", insertionSort, arr2, n);
  sort::testSort("选择排序", selectionSort, arr3, n);
  sort::testSort("归并排序", mergeSort, arr4, n);
  sort::testSort("快速排序", quickSort, arr5, n);

  // sort::printArr(arr, n);
  // sort::printArr(arr2, n);
  // sort::printArr(arr5, n);

  delete[] arr;
  return 0;
}