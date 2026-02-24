# Comment :
#Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
#
#Each product is guaranteed to fit in a 32-bit integer.
#
#Follow-up: Could you solve it in 
#𝑂
#(
#𝑛
#)
#O(n) time without using the division operation?
#
#Example 1:
#
#Input: nums = [1,2,4,6]
#
#Output: [48,24,12,8]

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        print(f"The nums is {nums}")
        from collections import Counter
        product = 1
        zero_count = Counter(nums)[0]

        if zero_count > 1:
            return [0] * len(nums)
        for num in nums:
            if num != 0:
                product *= num
        if zero_count == 1:
            return [product if num == 0 else 0 for num in nums]
        return [product // num for num in nums]



    def productExceptSelf2(self, nums: List[int]) -> List[int]:
        print(f"The nums is {nums}")
        # without division
        # prefix and suffix but with O(n2)
        out = []
        for i,num in enumerate(nums):
            prefix_product = 1 
            suffix_product = 1
            for p in range(0,i):
                prefix_product *= nums[p]
            for s in range(i+1,len(nums)):
                suffix_product *= nums[s]

            out.append(prefix_product*suffix_product)

        return out
    
    def productExceptSelf3(self, nums: List[int]) -> List[int]:
        # Prefix and suffix but with O(n)
        # Instead of computing prefixes and suffixes for each element and then going over the prefix sub-array for computing the prefix, leading to O(n2), 
        # Directly, first compute the prefixes in one pass
        # Second, compute suffixes from the opposite end, in one pass.
        # You can multiply the two suffixes in place of the out array.
        # This is different from the second method, because we are not going over the array again in each element phase.
        n = len(nums)
        out = [1] * n
        # Compute the prefix arrays
        prefix =1
        for i in range(n):
            out[i] = prefix
            prefix *= nums[i]
        # Compute the suffix arrays
        suffix = 1
        for i in range(n-1, -1, -1):
            out[i] *= suffix
            # Key thing here, is to product the existing prefix compute and the suffix compute to get the result.
            suffix *= nums[i]


        return out
    


nums = [1,2,4,0,6]
nums2 = [1,2,4,6]
s = Solution()
print(s.productExceptSelf(nums))
print(s.productExceptSelf2(nums))
print(s.productExceptSelf2(nums2))
print(s.productExceptSelf3(nums2))

