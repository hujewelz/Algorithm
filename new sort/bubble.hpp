#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(T *arr, int n) {
  for(int i = 0; i < n - 1; i++)
  {
    bool sorted = true;
    for(int j = 0; j < n - i - 1; j++)
      if (arr[j+1] < arr[j]) {
        swap(arr[j], arr[j+1]);
        sorted = false;
      }
      
    if (sorted) break;
  }
  
}