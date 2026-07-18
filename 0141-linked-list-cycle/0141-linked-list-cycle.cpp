/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
    if(head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr)
        {
            fast = fast->next;

            if(fast->next != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if(fast == slow) return true;
        }

        return false;
    }
};