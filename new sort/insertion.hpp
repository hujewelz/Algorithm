#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T *arr, int n) {
  for(int i = 1; i < n; i++)
  {
    T tmp = arr[i];
    int j; // 保存元素 tmp应该插入的位置
    for(int j = i; j > 0 && arr[j-1] < tmp; j--)
    {
      arr[j] = arr[j-1];
    }
    if (i != j) 
      arr[j] = tmp;
  }
}