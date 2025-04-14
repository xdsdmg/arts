#include <stdio.h>

int firstMissingPositive(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    int ind = nums[i] <= 0 ? -1 : nums[i] - 1;

    if (i == ind || ind < 0 || nums[i] > numsSize || nums[i] == nums[ind])
      continue;

    int j = i;
    while (
        !(j == ind || ind < 0 || nums[j] > numsSize || nums[j] == nums[ind])) {
      nums[ind] = nums[j] ^ nums[ind];
      nums[j] = nums[j] ^ nums[ind];
      nums[ind] = nums[j] ^ nums[ind];

      ind = nums[j] <= 0 ? -1 : nums[j] - 1;
    }
  }

  int res = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] <= 0 || nums[i] > numsSize || nums[i] != i + 1) {
      res = i + 1;
      break;
    }
  }
  res = res > 0 ? res : numsSize + 1;

  return res;
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
