// Last updated: 4/4/2026, 12:38:41 am
1class Solution {
2public:
3    void reorderList(ListNode* head) {
4        if (!head || !head->next) return;
5
6        // Step 1: Find middle
7        ListNode* slow = head;
8        ListNode* fast = head;
9
10        while (fast->next && fast->next->next) {
11            slow = slow->next;
12            fast = fast->next->next;
13        }
14
15        // Step 2: Reverse second half
16        ListNode* prev = nullptr;
17        ListNode* curr = slow->next;
18
19        while(curr) {
20            ListNode* next = curr->next;
21            curr->next = prev;
22            prev = curr;
23            curr = next;
24        }
25        slow->next = nullptr;
26
27        // Step 3: Merge
28        ListNode* l1 = head;
29        ListNode* l2 = prev;
30
31        while (l2) {
32            ListNode* n1 = l1->next;
33            ListNode* n2 = l2->next;
34
35            l1->next = l2;
36            l2->next = n1;
37
38            l1 = n1;
39            l2 = n2;
40        }
41    }
42};