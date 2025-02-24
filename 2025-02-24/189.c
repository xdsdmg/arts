/*
 * https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked
 * */

#include <stdio.h>

void rotate_by_one(int *nums, int numsSize) {
  if (numsSize <= 1)
    return;

  for (int i = 0, tmp, last = nums[0]; i < numsSize; i++) {
    int index = (i + 1) % numsSize;
    tmp = nums[index];
    nums[index] = last;
    last = tmp;
  }
}

void rotate(int *nums, int numsSize, int k) {
  k = k % numsSize;
  for (int i = 0; i < k; i++)
    rotate_by_one(nums, numsSize);
}

int main(int argc, char *argv[]) {
  int nums[7] = {1, 2, 3, 4, 5, 6, 7};
  int nums_size = 7, k = 10;

  rotate(nums, nums_size, k);

  for (int i = 0; i < nums_size; i++)
    printf("%d\n", nums[i]);

  return 0;
}
