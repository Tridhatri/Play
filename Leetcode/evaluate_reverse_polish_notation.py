'''
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.
'''

class Solution:
    def evalRPN(self, tokens: List[str])-> int :
        operators = ['+', '-', '*', '/']
        stack = []
        for c in tokens:
            if c in operators:
                #+
                #pop two times
                #and operate and push
                r1 = stack.pop()
                print(f"r1 is {r1}")
                r2 = stack.pop()
                print(f"r2 is {r2}")
                if c == '+':
                    r3 = r2 + r1
                    self.pushing_print(r3)
                    stack.append(int(r3))
                elif c == '*':
                    r3 = r2 * r1
                    self.pushing_print(r3)
                    stack.append(int(r3))
                elif c == '-':
                    r3 = r2 - r1
                    self.pushing_print(r3)
                    stack.append(int(r3))
                elif c == '/':
                    r3 = r2 / r1
                    self.pushing_print(r3)
                    stack.append(int(r3))

                # Operate on past two numbers
            else:
                # numbers
                print(f"Pushed the number {c}")
                stack.append(int(c))

        if(len(stack)):
            return stack.pop()
        else :
            return -1

    def pushing_print(self, num):
        print(f"Pushing the num : {num}")




'''
tokens = ["1","2","+","3","*","4","-"]
stack = 5

Output: 5

Explanation: ((1 + 2) * 3) - 4 = 5

'''

tokens = ["1","2","+","3","*","4","-"]
tokens1 = ["1","2","+","3","*","3","/"]

s = Solution()
print(s.evalRPN(tokens))
print()
print()
print()
print(s.evalRPN(tokens1))
