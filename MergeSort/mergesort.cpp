#include <iostream>
#include <algorithm>
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

template <typename T>
void insertionSort(T *arr, int n) {
  for(int i = 1; i < n; i++)
  {
    for(int j = i; j > 0 && arr[j] < arr[j-1]; j--)
    {
      swap(arr[j], arr[j-1]);
    }
  }
}

template <typename T>
void selectionSort(T *arr, int n) {
  for(int i = 0; i < n; i++)
  {
    int min = i;
    for(int j = i + 1; j < n; j++)
      if (arr[j] < arr[min]) 
        min = j;
    
    swap(arr[i], arr[min]);
  }
}

int main() {
  int arr[10];
  for(int i = 0; i < 10; i++)
  {
    arr[i] = random() % 100;
  }
  
  // mergeSort(arr, 10);
  // insertionSort(arr, 10);
  selectionSort(arr, 10);

  for(int i = 0; i < 10; i++)
  {
    cout << arr[i] << ",";
  }
  

  return 0;
}