#include <iostream>
using namespace std;

template <typename T>
void __merge(T *arr, int l, int mid, int r) {
  T tmp[r-l+1];
  for(int i = l; i <= r; i++)
  {
    tmp[i-l] = arr[i];
  }

  int i = l, j = mid + 1;
  for(int k = l; k <= r; k++)
  {
    if (i > mid) {
      arr[k] = tmp[j-l];
      j++;
    } else if (j > r) {
      arr[k] = tmp[i-l];
      i++;
    } else if (tmp[i-l] < tmp[j-l]) {
      arr[k] = tmp[i-l];
      i++;
    } else {
      arr[k] = tmp[j-l];
      j++;
    }
  }
}

template <typename T>
void __mergeSortRecursively(T *arr, int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = l + (r - l) / 2;
  __mergeSortRecursively(arr, l, mid);
  __mergeSortRecursively(arr, mid + 1, r);
  if (arr[mid] > arr[mid + 1])
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T *arr, int n) {
  __mergeSortRecursively(arr, 0, n-1);
}


