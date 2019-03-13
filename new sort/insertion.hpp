#include <iostream>

using namespace std;

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