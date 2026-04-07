// Last updated: 8/4/2026, 3:09:08 am
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
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14        
15
16        ListNode* f = head;  
17        for(int i = 0; i < n; i++) {
18            f = f->next;
19        } 
20        if(!f) return head->next;
21        ListNode* s = head;
22
23        while(s) {
24            if(f && f->next == nullptr) {
25                s->next = s->next->next;
26            } 
27            if(f) {
28                f = f->next;
29            }
30            s = s->next;
31        }
32
33        return head;
34
35    }
36};