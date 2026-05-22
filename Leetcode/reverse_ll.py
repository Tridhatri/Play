from typing import Optional
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr  = head
        prev = None
        i = 0
        
        while(curr): 
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
        

        return prev.val

head = []
liss = ListNode(5, None)
liss2 = ListNode(6, None)
liss.next = liss2
head.append(liss)
head.append(liss2)

#print(f"head is : {head}")
#print(f"head[0] is : {head[0]}")
#print(f"head[0].val is : {head[0].val}")
#print(f"head[0].next is : {head[0].next}")
#print(f"head[1] is : {head[1]}")
#print(f"head[0].next.val is : {head[0].next.val}")
#print(f"head[0].next.next is : {head[0].next.next}")

s = Solution()
print(s.reverseList(liss))


