'''

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

Example 1:

Input: head = [2,4,6,8]

Output: [2,8,4,6]
Example 2:

Input: head = [2,4,6,8,10]

Output: [2,10,4,8,6]
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: [ListNode]) -> None:
        p1 = head
        p2 = head
        mapp = {}
        index = 0
        while(p2!= None):
            mapp[index] = p2
            if(p2.next!= None):
                p2 = p2.next
                index = index+1
            else:
                break
        #p2 is the tail
        print("Now p2 points to")
        print(p2.val)
        print(f"index is {index}")
        while(index!=1 and p2 and p1 ):
            n1 = p1.next
            n2 = mapp[index]
            index = index -1
            p1.next = p2
            print(f"{p1.val} next is {p2.val}")
            p1 = n1
            print(f"{p1.val} now points to {n1.val}")
            p2 = n2
            print(f"{p2.val} now points to {n2.val}")

        print("Done")
        print(f"index is {index}")
    def displayll(self, head):
        n = head
        while(n):
            print(n.val)
            n = n.next
            

        
n1 = ListNode(0, None)
n2 = ListNode(1, None)
n3 = ListNode(2, None)
n4 = ListNode(3, None)

n1.next = n2
n2.next = n3
n3.next = n4

s = Solution()        
print("Before reordering")
s.displayll(n1)
s.reorderList(n1)
print("After reordering")
s.displayll(n1)




