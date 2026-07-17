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
    int length(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        

        if(len == n){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        int position = len - n;
        ListNode* temp = head;

        while(position>1)
        {
            temp = temp->next;
            position--;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;


        return head;
    }
};