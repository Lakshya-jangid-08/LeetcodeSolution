// Last updated: 6/29/2026, 10:23:34 AM
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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* back = nullptr;
        ListNode* front = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;


        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            cnt += 1;

            if(cnt == left - 1) {
                front = temp;
            }
            if(cnt == left) {
                curr = temp;
                next = temp->next;
            }
            if(cnt == right + 1) {
                back = temp;
            }
            temp = temp->next;
        }
        temp = back;

        while(curr != temp) {
            
            curr->next = back;
            back = curr;
            curr = next;
            next = (next ? next->next : nullptr);

        }
        if(front) front->next = back;

        return (front ? head : back);

    }
};