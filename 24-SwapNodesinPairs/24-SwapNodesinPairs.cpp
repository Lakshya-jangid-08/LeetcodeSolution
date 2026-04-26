// Last updated: 4/26/2026, 7:11:36 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* swapPairs(ListNode* head) {
14        if(!head) return head;
15
16        ListNode* node1 = head;
17        ListNode* node2 = head->next;
18
19        while(node1 != nullptr && node2 != nullptr) {
20            node1->val = node1->val ^ node2->val;
21            node2->val = node1->val ^ node2->val;
22            node1->val = node1->val ^ node2->val;
23            node1 = node2->next;
24            node2 = (node1 ? node1->next : nullptr);
25        }
26
27        return head;
28
29    }
30};