// Last updated: 5/5/2026, 11:16:57 AM
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if (!head || !head->next || k == 0) return head;
15
16        int n = 1;
17        ListNode* tail = head;
18
19        while (tail->next) {
20            tail = tail->next;
21            n++;
22        }
23
24        tail->next = head;
25
26        k = k % n;
27
28        int steps = n - k - 1;
29        ListNode* newTail = head;
30
31        while (steps--) {
32            newTail = newTail->next;
33        }
34
35        ListNode* newHead = newTail->next;
36
37        newTail->next = nullptr;
38
39        return newHead;
40    }
41};