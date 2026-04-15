// Last updated: 4/15/2026, 10:53:53 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        ListNode* fast = head;
13        ListNode* slow = head;
14
15        while(fast && fast->next) {
16            fast = fast->next->next;
17            slow = slow->next;
18            if(slow == fast) return true;
19        }
20
21        return false;
22    }
23};