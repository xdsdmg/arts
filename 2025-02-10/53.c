/*
 *  https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked
 * */

#include <stdio.h>

int maxSubArray(int *nums, int numsSize) {
  if (nums == NULL || numsSize <= 0)
    return 0;

  int res = nums[0], last = nums[0];

  for (int i = 1; i < numsSize; i++) {
    last = last > 0 ? nums[i] + last : nums[i];
    res = last > res ? last : res;
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  printf("res: %d\n", maxSubArray(nums, 9));

  return 0;
}
