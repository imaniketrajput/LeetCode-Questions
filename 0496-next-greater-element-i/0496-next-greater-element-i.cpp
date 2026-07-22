class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        stack<int> st;

        st.push(-1);

        unordered_map<int, int> mp;

        for(int i=m-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};