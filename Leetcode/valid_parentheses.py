'''
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

'''

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        map_close_to_open = { ')' : '(', ']' : '[', '}' : '{' }
        for c in s:
            if len(stack) and c in map_close_to_open:
                print(f"Incoming closing bracket {c}")
                # Which means it is a closing bracket.
                # So, query for open bracket at the top of the stack.
                print(f"stack[-1] : {stack[-1]}")
                if len(stack) and stack[-1] == map_close_to_open[c]:
                    
                    # Which means we have found a opening bracket.
                    # And we can pop it and move on to the next char in stack.
                    stack.pop()
                    print(f"Popped {c}")
                else:
                    # Which means we have not found a opening bracket.
                    # That means, it is invalid because it needs to follow the order and it needs to be opened to be closed.
                    return False
                     
            else: 
                # Which means it is opening bracket.
                # So, you just add it to the stack.
                print(f"opening bracket {c}")
                stack.append(c)
                print(f"Pushed {c}")

        # Now only return if stack is empty after all the pushing and popping.
        if len(stack):
            return False
        else:
            return True
        
input1 = "[]"
input2 = "()[]"
input3 = "([])"
input3 = "([)]"
inputs = [input1, input2, input3]
s = Solution() 
for ins in inputs:
    print("")
    print(f"Checking for the input : {ins}")
    if s.isValid(ins):
        print("Valid parentheses!")
    else:
        print("Not Valid parentheses!")
