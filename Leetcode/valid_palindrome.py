'''
Question : 

Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).


'''



class Solution:
    def isPalindrome(self, s: str) -> bool:
        #s = s.strip().lower(),  Does not handle alpha numeric.
        s = ''.join(ch.lower() for ch in s if s.isalnum())
        # Join is used on a list of strings to join them into a single string using the delimitter in front of it.
        # Returns a list of characaters which are always alpha-numeric and not spacces.
        
        return s == s[::-1]


        # Or the most explicit versiosn is this
        #for i in range(len(s) // 2):
            #if s[i] != s[len(s) - 1 - i]:
                #return False
        #return True

lame_string = "racecar"
lame_string2 = "Was it a car or a cat I saw?"


s = Solution()
print(s.isPalindrome(lame_string))
print(s.isPalindrome(lame_string2))
