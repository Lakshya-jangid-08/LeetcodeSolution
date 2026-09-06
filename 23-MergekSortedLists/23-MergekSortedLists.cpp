// Last updated: 9/6/2026, 6:09:37 PM
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
12    struct compare {
13        bool operator()(ListNode* a, ListNode* b) {
14            return a->val > b->val;
15        }
16    };
17
18public:
19    ListNode* mergeKLists(vector<ListNode*>& lists) {
20        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
21
22        for(auto &list : lists) {
23            if(!list) continue;
24            pq.push(list);
25        }
26
27        ListNode* sol = new ListNode(0);
28        ListNode* tail = sol;
29
30        while(!pq.empty()) {
31            auto smallestList = pq.top(); pq.pop();
32            tail->next = smallestList;
33            tail = tail->next;
34            if(smallestList->next) 
35                pq.push(smallestList->next);
36        }
37        
38        return sol->next;
39    }
40};