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

    int getLength(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* collisionPoint(ListNode *headA, ListNode *headB, int d)
    {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(d){
            d--;
            t2 = t2->next;
        }

        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }

        return t1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int N1 = getLength(headA);
        int N2 = getLength(headB);

        if(N2 > N1)
        {
            return collisionPoint(headA, headB, N2-N1);
        }
        else{
            return collisionPoint(headB, headA, N1-N2);

        }

        return nullptr;


           
    }
};