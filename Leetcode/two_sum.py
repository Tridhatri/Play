# Two sum
'''

Psuedo-code-comments:

    # 2, hash [2] =0, # target = i + some_previous_i = target = nums[i] + nums[j],  nums[j] = target - nums[i] , 
    if we find hash_map[nums[j]] in hash_map valid, then we return i,hash_map[nums[j]]
    to_find = target - nums[i]
    if to_find in hash_map:
        return i, hash_map(to_find)

    else :
        # we did not find the to_find, 
        we just add it
        hash_map[nums[i]] = i


Examples :


#nums = [3,2,4]
#target = 6


'''


class Solution:
    def twoSum(self, nums : List[int], target : int) -> List[int]:
        hash_map = {}
        # Again hashmap cuz O(1) lookup, we can find the number in O(1) time, and we only need to loop through the array once O(n).
        # Overall complexity is O(n) time and O(n) space, we are storing the numbers in the hash_map, but we can also say that we are storing at most n numbers in the hash_map, so O(n) space.
        for i in range(len(nums)):
            # Add the numbers index, first
            to_find = target - nums[i]
            # We need to find this number if it is present in the hash_map
            #print(to_find, "  ",  hash_map)
            if to_find in hash_map:
                # We found it which means we need to return to_find index, i 
                return hash_map[to_find], i
            # Else we did not see the number yet
            hash_map[nums[i]] = i
            

        return None




nums = [3,2,4]
target = 6

sol = Solution()
result = sol.twoSum(nums, target)
print(result)
