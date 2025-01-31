<<<<<<< HEAD
"""
https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked
"""
=======
'''
https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked
'''
>>>>>>> fe5a600 (feat (wip): 2025-01-27)

from typing import List


def to_dict(s: str) -> dict:
    res = {}

    for c in s:
        res[c] = 1 if c not in res else res[c] + 1

    return res


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res: List[int] = []

        s_l, p_l = len(s), len(p)
        d = to_dict(p)

        for i in range(s_l):
            if i + p_l - 1 > s_l:
                break

            d_ = to_dict(s[i : i + p_l])
            if d == d_:
                res.append(i)

        return res


if __name__ == "__main__":
    s = "cbaebabacd"
    p = "abc"

    s_ = Solution()
    print(s_.findAnagrams(s, p))
