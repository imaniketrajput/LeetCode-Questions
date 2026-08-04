class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mini = nums[0];
        int maxi = nums.back();

        vector<int> res;

        set<int> st(nums.begin(), nums.end());

        for(int i=mini+1; i<=maxi-1; i++)
        {
            if(st.count(i)==0) res.push_back(i);
        }

        return res;

    }
};