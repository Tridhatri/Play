strs = ["Hello","World"]
from typing import List
class Solution:
    def encode(self, strs: List[str]) -> str:
        encoded_string = ""
        for s in strs:
           encoded_string += str(len(s)) + "#" + s 
        return encoded_string    

    def decode(self, s: str) -> List[str]:
        decoded_list = []
        # 5#Hello5#World
        i = 0
        print(s[1:2])
        while i < len(s):
            j = i
            while s[j] != "#":
                j +=1
            # j will be the # position
            # j+1 will be the start of the word
            length = int(s[i:j]) 
            decoded_list.append(s[j+1: j+1+length])
            # i should always be the start of the integer (lenght of word)
            i = length + j + 1 

        return decoded_list
            
        

s = Solution()
s1 = s.encode(strs)
print(s1)

s2 = s.decode(s1)
print(s2)
