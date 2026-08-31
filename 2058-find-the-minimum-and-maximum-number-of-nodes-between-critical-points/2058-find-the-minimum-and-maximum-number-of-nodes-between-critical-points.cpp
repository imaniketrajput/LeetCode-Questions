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

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;

        vector<int> cp;

        while(curr->next != nullptr)
        {
            pos++;

            if(curr->val > prev->val && curr->val > curr->next->val) // Local Maxima
            {
                cp.push_back(pos);
            }

            if(curr->val < prev->val && curr->val < curr->next->val) // Local Minima
            {
                cp.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
        }
        
        int s = cp.size();
        
        if(s < 2)
        {
            return {-1, -1};
        }

        int mini = INT_MAX;

        for(int i=1; i<s; i++)
        {
            mini = min(mini, cp[i]-cp[i-1]);
        }

        int maxi = cp.back() - cp.front();

        return {mini, maxi};

        
    }
};