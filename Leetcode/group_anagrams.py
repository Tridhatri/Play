strs = ["act","pots","tops","cat","stop","hat"]
# Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

'''
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Input: strs = ["x"]

Output: [["x"]]

Input: strs = [""]

Output: [[""]]
'''

from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        self.strs = strs
        strs = self.strs
        from collections import Counter
        Output = []
        hash_map = {}
        for i in range(len(strs)):
            key = tuple(sorted(Counter(strs[i]).items()))
            if key in hash_map:
                hash_map[key].append(i)
            else:
                hash_map[key] = [i]

        # Now you got the counters with the same anagrams with the indexes.
        for i in (hash_map):
            indexes = hash_map[i]
            # [1,2]
            values = []
            for j in indexes:
                values.append(strs[j])
            #values = ["as", "asf"]
            Output.append(values)
        return Output
    def sol2(self, strs: List[str]) :
        Output = defaultdict(list)
        for i in strs:
            key = tuple(sorted(i))
            Output[key].append(i)
        return list(Outputt.values())


    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:


sol = Solution()
print(sol.groupAnagrams(strs))
#Counter("ab") + Counter("bc")
# Counter({'b': 2, 'a': 1, Counter("ab") + Counter("bc")
# Counter({'b': 2, 'a': 1, 'c': 1})'c': 1})
