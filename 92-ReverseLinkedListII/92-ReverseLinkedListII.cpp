// Last updated: 4/18/2026, 10:58:52 AM
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
12    /**
13 * Definition for singly-linked list.
14 * struct ListNode {
15 *     int val;
16 *     ListNode *next;
17 *     ListNode() : val(0), next(nullptr) {}
18 *     ListNode(int x) : val(x), next(nullptr) {}
19 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
20 * };
21 */
22public:
23    ListNode* reverseBetween(ListNode* head, int left, int right) {
24        if (!head || left == right) return head;
25
26        ListNode* back = nullptr;
27        ListNode* front = nullptr;
28        ListNode* curr = head;
29        ListNode* next = head->next;
30
31
32        int cnt = 0;
33        ListNode* temp = head;
34        while(temp != nullptr) {
35            cnt += 1;
36
37            if(cnt == left - 1) {
38                front = temp;
39            }
40            if(cnt == left) {
41                curr = temp;
42                next = temp->next;
43            }
44            if(cnt == right + 1) {
45                back = temp;
46            }
47            temp = temp->next;
48        }
49        temp = back;
50
51        while(curr != temp) {
52            
53            curr->next = back;
54            back = curr;
55            curr = next;
56            next = (next ? next->next : nullptr);
57
58        }
59        if(front) front->next = back;
60
61        return (front ? head : back);
62
63    }
64};