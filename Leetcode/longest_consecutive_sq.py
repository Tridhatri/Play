# Longest Consecutive Array , Neetcode #150
''' 
Question:
    Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

    A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

    You must write an algorithm that runs in O(n) time.

Examples:

    Input: nums = [2,20,4,10,3,4,5]

    Output: 4

    -------
    Input: nums = [0,3,2,5,4,6,1,1]

    Output: 7

'''

class Solution:
    def longestConsecutive(self, nums: List[int])-> int:
        # Brute force approach is to sort the array and then iterate over it and find the longest consecutive sequence.
        # Maybe you can sort it and find out a number of sequences and then find the maximum lenght of them. 
        nums_s = sorted(set(nums))
        # O(n.logn)
        # Sorted in a list
        # now, just iterate over the numbers , every second element should be 1 greater than the last.
        # So, 
        longest_sq_array = [1] * len(nums_s)
        for global_i in range(len(nums_s)-1):
            local_i = global_i
            while(local_i < (len(nums_s) -1)):
                # Potentially O(n2)
                diff = nums_s[local_i +1] - nums_s[local_i]
                if (diff==1 or diff==0):
                    longest_sq_array[global_i]+=1
                    local_i+=1
                else:
                    break
        
        return max(longest_sq_array)
     

    def longestConsecutive2(self, nums: List[int])-> int:
        # Anyways,
        # Trying to solve in O(n)
        # There is a way to cut down counting sequences by not taking into account every element in the array and trying to find the sequence.
        # A better way is to only consider the elements which are sequence headers.
        # This way you are not counting each element to be a sequence header.
        # You are only considering the sequence headers by basically, iterating over each element, from the start 
        # First finding if it is a valid sequence header by looking for the element -1 in the array, if it is a valid sq header, then 
        # finding out the largest sequence from the element 
        # Basically, do not bother about the sequence elements in the  current state. You do not have to this anyway, because in the check for valid sq header, you eliminate double checking.
        # Go to the next sequence header, do the same
        # End up with multiple sequences
        # Find the maximum length among all them

        # You can do a set here. WHY? cuz 
        # A.To eliminate duplicates. 
        # B.Becomes easy to check the sq header 
        # C. Becomes easy to check the next element in the sequence. 
        # D. It is O(n) to create a set, but it is worth it, because it will make the rest of the operations O(1) and we will not have to worry about duplicates.

        nums_set = set(nums) # O(n) to create a set, but it is worth it, because it will make the rest of the operations O(1) and we will not have to worry about duplicates.
        # finding the sq header
        longest_sq_count = 1
        for i in nums_set: # O(n)
            if i-1 in nums_set:
                # Then basically it is not a sq header
                continue
            else:
                sq_header = i
                current_sq_count = 1
                # Now to try iterating by 1 and see if it exists in set as much as possible
                while(sq_header+1 in nums_set): # O(1)
                     current_sq_count +=1
                     sq_header +=1
                longest_sq_count = max(current_sq_count, longest_sq_count)

        return longest_sq_count


s = Solution()
nums1 = [2,20,4,10,3,4,5]
nums2 = [0,3,2,5,4,6,1,1]
#print(s.longestConsecutive(nums1))
print(s.longestConsecutive2(nums1))
print(s.longestConsecutive2(nums2))
