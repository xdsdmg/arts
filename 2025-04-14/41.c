#include <stdio.h>

int firstMissingPositive(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    int ind = nums[i] <= 0 ? -1 : nums[i] - 1;

    while (i != ind && ind >= 0 && nums[i] <= numsSize &&
           nums[i] != nums[ind]) {
      nums[ind] = nums[i] ^ nums[ind];
      nums[i] = nums[i] ^ nums[ind];
      nums[ind] = nums[i] ^ nums[ind];

      ind = nums[i] <= 0 ? -1 : nums[i] - 1;
    }
  }

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] <= 0 || nums[i] > numsSize || nums[i] != i + 1)
      return i + 1;
  }

  return numsSize + 1;
}

int main(int argc, char *argv[]) {
  int nums[4] = {3, 4, -1, 1};
  int numsSize = 4;

  printf("res: %d\n", firstMissingPositive(nums, numsSize));

  for (int i = 0; i < numsSize; i++)
    printf("%d ", nums[i]);
  printf("\n");

  return 0;
}
