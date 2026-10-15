class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        int total = 0;
        for(int i=0; i<n; i++)
        {
            int j = i;

            while(j<n)
            {
                st.insert(nums[j]);
                total += st.size() * st.size();
                j++;
            }

            st.clear();

        }

        return total;
    }
};