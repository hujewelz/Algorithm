#include <iostream>
#include <string>
#include "insertion.hpp"
#include "selection.hpp"
#include "bubble.hpp"
#include "merge.hpp"
#include "quick.hpp"

using namespace std;

namespace sort {

  template <typename T>
  T *randomArr(int n) {
    T *arr = new T[n];
    for(int i = 0; i < n; i++)
    {
      arr[i] = random() % n + 1;
    }
    return arr;
  }

  template <typename T>
  void testSort(const string &name, void (*sort)(T *, int), T *arr, int n) {
    clock_t begin = clock();
    sort(arr, n);
    double duration = double(clock() - begin) / CLOCKS_PER_SEC;

    cout << name << " cost " << duration << "s" << endl;
    
  }

  template <typename T>
  T *copyedArr(T *arr, int n) {
    T *result = new T[n];
    copy(arr, arr+n, result);
    return result;
  }

  template <typename T>
  void printArr(T *arr, int n) {
    for(int i = 0; i < n; i++)
      cout << arr[i] << ", ";
    cout << endl;
  }

};