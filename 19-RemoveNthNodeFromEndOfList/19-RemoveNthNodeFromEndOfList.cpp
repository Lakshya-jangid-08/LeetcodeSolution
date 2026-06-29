// Last updated: 6/29/2026, 10:23:54 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        ListNode* f = head;  
        for(int i = 0; i < n; i++) {
            f = f->next;
        } 
        if(!f) return head->next;
        ListNode* s = head;

        while(s) {
            if(f && f->next == nullptr) {
                s->next = s->next->next;
            } 
            if(f) {
                f = f->next;
            }
            s = s->next;
        }

        return head;

    }
};