# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        lar = ListNode(0)
        lar.next = head
        pre = lar
        less = ListNode(0)
        p = less
        while pre != None and pre.next != None:
            if pre.next.val < x:
                p.next = pre.next

                pre.next = pre.next.next
                p.next.next = None
                p = p.next
            else:
                pre = pre.next
        p.next = lar.next
        return less.next