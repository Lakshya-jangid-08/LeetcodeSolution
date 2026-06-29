# Last updated: 6/29/2026, 10:21:10 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        # reverse half link
        # TC for bruteforce => O(n * n);
        # optimal appproach -> reverse the 1st half ll & itr 1st & 2nd half

        fast = head
        slow = head
        prev = None
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            head.next = prev
            prev = head
            head = slow

        # head & slow hai 
        res = 0
        while slow:
            curr = prev.val + slow.val
            res = max(res, curr)
            prev = prev.next
            slow = slow.next
        return res

        