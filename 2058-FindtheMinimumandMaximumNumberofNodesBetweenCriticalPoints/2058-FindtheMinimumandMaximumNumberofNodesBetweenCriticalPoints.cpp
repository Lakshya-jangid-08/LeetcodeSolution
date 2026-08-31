// Last updated: 8/31/2026, 6:36:07 PM
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
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        int l = -1, r = -1;
15        int prev = -1, curr = -1;
16
17        int pv = head->val;
18        head = head->next;
19        int v = head->val;
20        head = head->next;
21        if(!head) return {-1, -1};
22
23        int idx = 1;
24        int diff = 1e7;
25
26        while(head) {
27            int nv = head->val;
28            head = head->next;
29
30            if((pv > v and nv > v) or (pv < v and nv < v)) {
31                if(l == -1) l = idx;
32                prev = curr;
33                curr = idx;
34                r = idx;
35            } 
36
37            pv = v; v = nv;
38            if(prev != -1) diff = min(diff, curr - prev);
39            idx += 1;
40        }
41        if(r == l) return {-1, -1};
42        return {diff, r - l};
43    }
44};