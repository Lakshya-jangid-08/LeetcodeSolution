// Last updated: 6/3/2026, 9:11:36 AM
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
13    ListNode* deleteMiddle(ListNode* head) {
14        // if it is fast - slow pointer 
15        if(head == nullptr || head->next == nullptr) return nullptr;
16        ListNode* slow = head;
17        ListNode* fast = head;
18        ListNode* prev = head;
19
20        while(fast != nullptr && fast->next != nullptr) {
21            prev = slow;
22            slow = slow->next;
23            fast = fast->next->next;
24        }
25
26        prev->next = slow->next;
27
28        return head;
29
30    }
31};