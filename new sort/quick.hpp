#include <iostream>

using namespace std;

template <typename T>
void __quickSort(T *arr, int l, int r) {
  if (l >= r) return;

  //int index = random() % (r-l);
  T partion = arr[l];
  //cout << partion << "index: " << index << endl;
  int i = l, j = r;
  while ( i < j){
    while (i < j && arr[j] >= partion)
      j--;
    arr[i] = arr[j];

    while (i < j && arr[i] < partion) 
      i++;
    arr[j] = arr[i];
  }
  arr[i] = partion;
  __quickSort(arr, l, i-1);
  __quickSort(arr, i+1, r);
}

template <typename T>
void quickSort(T *arr, int n) {
  __quickSort(arr, 0, n-1);
}