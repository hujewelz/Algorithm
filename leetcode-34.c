#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0, j = numsSize - 1;
    int mid = (j - i) / 2 + i;
    int start = -1, end = -1;
    while (i < j && i < numsSize -1 && j > 0) {
        mid = (j - i) / 2 + i;
        if (target == nums[mid]) {
            if (start == -1) { start = i; }
            end = i;
            break;
        }
        else if (target < nums[mid]) {
            j = mid - 1; 
        } else if (target > nums[mid]) {
            i = mid + 1;
        }
    }

    // for (int r = j; r >= i; r--) {
        // if (nums[r] == target) {
            // end = r;
            // break;
        // }
    // }
    printf("[%d, %d]\n", start, end);
    *returnSize = start;
    *(returnSize +1) = end;
    return returnSize;
}

int main() {
  int arr[] = {5, 7, 7, 8, 8, 10};
  int size = sizeof(arr) / 4;
  int result[2];
  int *a = searchRange(arr, size, 8, result);
  printf("a: %p", a);
  printf("\n[%d, %d]\n", *a, *(a + 1));
}