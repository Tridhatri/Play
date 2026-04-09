'''
Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in O (1)
'''


class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        print("Returning the min")
        return min(self.stack)
    

    def display_stack(self) -> None:
        print("Displaying the stack")
        for i in self.stack:
            print(f"{i}  ")
        print("End of display of stack")



#JInput = ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

#Output = [null,null,null,null,0,null,2,1]

m = MinStack()
m.push(1)
m.push(2)
m.push(0)
m.display_stack()
print(m.getMin())
m.pop()
print(m.top())
print(m.getMin())

