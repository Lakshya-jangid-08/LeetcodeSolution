// Last updated: 4/18/2026, 10:36:01 AM
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
13    ListNode* reverseList(ListNode* head) {
14        if(!head) return nullptr;
15
16        ListNode* prev = nullptr;
17        ListNode* curr = head;
18        ListNode* next = head->next;
19    
20        while(curr) {
21             
22            curr->next = prev;
23            prev = curr;
24            curr = next;
25            next = (next ? next->next : nullptr);
26
27        }
28
29        return prev;
30    }
31};