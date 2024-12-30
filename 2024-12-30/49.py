"""
https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
"""

from typing import List, Dict


def str2map(str) -> Dict:
    res = {}

    for c in str:
        res[c] = 1 if c not in res else res[c] + 1

    return res


def cmp_map(map_1, map_2) -> bool:
    if len(map_1) != len(map_2):
        return False

    for k in map_1:
        if (k not in map_2) or (map_1[k] != map_2[k]):
            return False

    return True


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        records: List[Dict] = []

        for s in strs:
            flag = False
            m = str2map(s)

            for r in records:
                if not cmp_map(m, r["map"]):
                    continue

                r["arr"].append(s)
                flag = True

            if not flag:
                records.append({"map": m, "arr": [s]})

        return [r["arr"] for r in records]


if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    s = Solution()
    res = s.groupAnagrams(strs)
    print(res)
