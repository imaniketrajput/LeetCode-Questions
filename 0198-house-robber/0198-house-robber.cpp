class Solution {
public:

    vector<int> dp;

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];

        dp.assign(n+1, -1);

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++)
        {
            int val = nums[i-1];

            int take = val + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }

        return dp[n];
    }
};