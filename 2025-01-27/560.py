"""
https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        length = len(nums)

        if length == 0:
            return 0

        d = {0: 1}
        s = 0
        for i in range(length):
            s += nums[i]
            if s - k in d:
                res += d[s - k]
            d[s] = d[s] + 1 if s in d else 1

        return res


if __name__ == "__main__":
    nums = [-1, -1, 1]
    k = 0

    s = Solution()
    print(s.subarraySum(nums, k))
