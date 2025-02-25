/*
 * https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked
 * */

#include <stdio.h>

void rotate(int *nums, int numsSize, int k) {
  if (numsSize <= 1)
    return;

  k = k % numsSize;
  if (k == 0)
    return;

  int n = numsSize % k == 0 ? k : 1;

  for (int i = 0; i < n; i++) {
    int last = nums[i];
    int index = (i + k) % numsSize;
    int c = index;

    do {
      last = last ^ nums[index];
      nums[index] = last ^ nums[index];
      last = last ^ nums[index];

      index = (index + k) % numsSize;
    } while (index != c);
  }
}

int main(int argc, char *argv[]) {
  int nums[4] = {-1, -100, 3, 99};
  int nums_size = 4, k = 2;

  rotate(nums, nums_size, k);

  for (int i = 0; i < nums_size; i++)
    printf("%d\n", nums[i]);

  return 0;
}
