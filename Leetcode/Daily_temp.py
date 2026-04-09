'''
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]

'''
class Solution:
    def dailyTemperatures1(self, temperatures: List[int]) -> List[int]:
        # Brute force , O(n2)
        result = []
        for i, val  in enumerate(temperatures):
            count = 0
            j = i
            while(j < len(temperatures)):
                if (temperatures[j] > val):
                        result.append(count)
                        break
                else:
                    count = count + 1
                    j = j + 1
            if(j >= len(temperatures)):
                result.append(0)
        return result

    def dailyTemperatures2(self, temperatures: List[int]) -> List[int]:
        result = [] 
        for i,val in enumerate(temperatures):
            stack = []
            count = 0
            j = i + 1
            stack.append(val)
            #displaystack(stack)
            while(j < len(temperatures)  and stack and temperatures[j] < val):
                stack.append(temperatures[j]) 
                #displaystack(stack)
                count =  count + 1
                j = j +1
            count = count +1
            if (j >= len(temperatures)):
                result.append(0)
            else:
                result.append(count)

        return result


'''
def displaystack(stack):
    print("Displaying stack")
    for i in stack:
        print(i)
    print("End of dispalyed stack")
'''

s = Solution()
temperatures = [30,38,30,36,35,40,28]
temperatures2 = [22,21,20]
print("Using brute force")
print(s.dailyTemperatures1(temperatures))
print()
print()
print(s.dailyTemperatures1(temperatures2))
print()
print()
print("Using Stack ")
print(s.dailyTemperatures2(temperatures))
print()
print()
print(s.dailyTemperatures2(temperatures2))
