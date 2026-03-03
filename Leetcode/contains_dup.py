num3 = [1,2,3, 5, 6,7, 5 ]



class Solution:
    def contains_dup(self , nums: List[int]) -> bool :
        self.nums = nums
        hash_map = {}
        for i in range(len(self.nums)):
            if self.nums[i] in hash_map:
                return True,hash_map[self.nums[i]]
            hash_map[self.nums[i]] = i 
        return False, -1
        
    def sec (self , nums) :
        self.nums = nums
        nums = self.nums 
        nums.sort() 
        i = 0
        j = i+1 
        while(i<len(nums) and j < (len(nums) -1)):
            if nums[i] == nums[j]:
                return True
            i = i + 1
            j = j + 1
        return False


sol = Solution()

print(sol.contains_dup(num3))
print(sol.sec(num3))

