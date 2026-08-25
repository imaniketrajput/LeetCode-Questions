class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st(begin(nums), end(nums));

        for(int i=1; i<=101; i++)
        {
            if(st.find(k*i) == st.end())
            {
                return k * i;
            }
        }

        return 0;
    }
};