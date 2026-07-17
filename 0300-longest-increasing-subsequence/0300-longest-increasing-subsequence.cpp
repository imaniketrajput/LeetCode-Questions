class Solution {
public:

    int solve(vector<int>& nums, int lastIdx, int i, vector<vector<int> >& dp)
    {
        if(i>=nums.size()) return 0;


        if(dp[lastIdx+1][i] != -1) return dp[lastIdx+1][i];

        int curr = nums[i];
        int inc = 0;
        if(lastIdx == -1 || curr > nums[lastIdx])
        {
            inc = 1 + solve(nums, i, i+1, dp);
        }

        int ex = 0 + solve(nums, lastIdx, i+1, dp);

        dp[lastIdx+1][i] = max(inc, ex);

        return dp[lastIdx+1][i];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lastIndx = -1;
        int i=0;

        vector<vector<int> > dp(n+2, vector<int>(n+1, -1));
        return solve(nums, lastIndx, i, dp);

    }
};