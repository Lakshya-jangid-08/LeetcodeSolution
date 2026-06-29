// Last updated: 6/29/2026, 10:21:16 AM
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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        int res = 0;
        while(slow != nullptr) {
            res = max(res, slow->val + prev->val);
           prev = prev->next; slow = slow->next;
        }
        return res;
    }
};