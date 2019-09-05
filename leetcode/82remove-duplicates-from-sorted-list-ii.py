# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        p = head
        ans = ListNode(0)
        pre = ans
        pre.next = p
        f = False
        while p != None and p.next != None:
            f = False
            while p.next != None and p.val == p.next.val:
                p.next = p.next.next
                f = True

            if f:
                p = p.next
                pre.next = pre.next.next
            else:
                pre = p
                p = p.next

        return ans.next