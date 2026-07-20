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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;

        while(t1 || t2 || carry)
        {
            int x = t1 ? t1->val : 0;
            int y = t2 ? t2->val : 0;

            int totalSum = x + y + carry;
            int digit = totalSum % 10;
            carry = totalSum / 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }

        return dummy->next;


    }
};