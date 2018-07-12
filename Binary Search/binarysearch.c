#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 二分查找
 * @param arr   排序后的数组
 * @param target 目标元素
 * @param n      数组长度
 * @return 返回目标元素在数组中的位置，找不到返回 -1
 **/
int binarySearch(int *arr, int target,  int n) {
  int l = 0;
  int r = n - 1;
  int mid = 0;
  while (l < r) {
    // 计算中间位置的值
    mid = l + (r - l) / 2; 
    if (target == arr[mid]) {
      return mid;
    } 
    if (target < arr[mid]) {
      // 如果目标值小于中间值，说明目标值在左边
      r = mid -1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

// 使用递归
int _binarySearch(int *arr, int target, int left, int right) {
  int mid = left + (right - left) / 2;
  if (target == arr[mid])
    return mid;
  if (target < arr[mid]) {
    return _binarySearch(arr, target, left, mid-1);
  }
  else {
    return _binarySearch(arr, target, mid+1, right);
  }
}

int binarySearch2(int *array, int target, int n) {
  return _binarySearch(array, target, 0, n);
}



int main() {
  int array[] = {1, 3, 23, 45, 56, 68, 89, 98};
  int result = binarySearch2(array, 68, 8);
  printf("\nindex: %d", result);
  return 0;
}