"""
https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked
"""

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = sorted(list(set(nums)))
        end = len(nums) - 1

        if end < 0:
            return 0

        res, tmp = 1, 1

        r = 0
        while True:
            if r == end:
                res = tmp if tmp > res else res
                break

            r += 1
            if nums[r] == nums[r - 1] + 1:
                tmp += 1
            else:
                res = tmp if tmp > res else res
                tmp = 1

        return res


if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2]
    # nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
    # nums = [0, 1, 2, 1]

    s = Solution()
    print(s.longestConsecutive(nums))
