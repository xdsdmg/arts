"""
https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
"""

import collections
from typing import List, Dict
from collections import Counter


def str2map(str) -> Dict:
    return dict(Counter([c for c in str]))


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return []

        records: List[Dict] = []

        for s in strs:
            flag = False
            m = str2map(s)

            for r in records:
                if m != r["map"]:
                    continue

                r["arr"].append(s)
                flag = True

            if not flag:
                records.append({"map": m, "arr": [s]})

        return [r["arr"] for r in records]

    def groupAnagrams_2(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return []

        mp = collections.defaultdict(list)

        for str in strs:
            key = "".join(sorted(str))
            mp[key].append(str)

        return list(mp.values())


if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    s = Solution()
    res = s.groupAnagrams_2(strs)
    print(res)
