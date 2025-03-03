/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *res = (int *)malloc(numsSize * sizeof(int));

  int p = 1, s = 1;
  for (int i = 0; i < numsSize; i++) {
    res[i] = p;
    p *= nums[i];
  }
  for (int i = numsSize - 1; i >= 0; i--) {
    res[i] *= s;
    s *= nums[i];
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums[4] = {1, 2, 3, 4};
  int numsSize = 4;
  int *returnSize = (int *)malloc(sizeof(int));

  int *res = productExceptSelf(nums, numsSize, returnSize);

  for (int i = 0; i < *returnSize; i++)
    printf("%d\n", res[i]);

  return 0;
}
