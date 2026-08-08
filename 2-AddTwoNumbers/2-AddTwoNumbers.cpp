// Last updated: 8/8/2026, 6:14:59 PM
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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        int carry = 0;
15        ListNode* head = new ListNode();
16        ListNode* temp = head;
17
18        while(l1 != nullptr || l2 != nullptr) {
19            int val1 = (l1 != nullptr ? l1->val : 0);
20            int val2 = (l2 != nullptr ? l2->val : 0);
21            int sum = val1 + val2 + carry;
22            carry = sum / 10;
23            sum %= 10;
24            temp->next = new ListNode(sum);
25            temp = temp->next;
26            if(l1) l1 = l1->next;
27            if(l2) l2 = l2->next;
28        }
29
30        if(carry != 0) {
31            temp->next = new ListNode(carry);
32        }
33        return head->next;
34    }
35};