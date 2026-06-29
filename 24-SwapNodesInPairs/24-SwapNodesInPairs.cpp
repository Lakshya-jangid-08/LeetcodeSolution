// Last updated: 6/29/2026, 10:23:53 AM
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;

        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while(node1 != nullptr && node2 != nullptr) {
            node1->val = node1->val ^ node2->val;
            node2->val = node1->val ^ node2->val;
            node1->val = node1->val ^ node2->val;
            node1 = node2->next;
            node2 = (node1 ? node1->next : nullptr);
        }

        return head;

    }
};