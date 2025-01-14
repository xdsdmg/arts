"""
https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked
"""

from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        zero_total = 0
        length = len(nums)

        for i in range(length):
            if nums[i] == 0:
                zero_total += 1

        index = 0
        for i in range(length):
            if nums[i] != 0:
                nums[index] = nums[i]
                index += 1

        for i in range(length - zero_total, length):
            nums[i] = 0


if __name__ == "__main__":
    nums = [0, 1, 0, 3, 12]
    s = Solution()
    s.moveZeroes(nums)
    print(nums)
