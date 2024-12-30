"""
https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
"""

from typing import List, Dict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        records: List[Dict] = []

        for s in strs:
            for r in records:
                if len(s) != len(r):
                    continue
                for c in s:
                    if c not in r["map"]:
                        continue
                r["arr"].append(s)

        return [r["arr"] for r in records]


if __name__ == "__main__":
    s = Solution()
    s.groupAnagrams([])
