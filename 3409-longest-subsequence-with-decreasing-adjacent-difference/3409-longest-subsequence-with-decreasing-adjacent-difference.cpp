class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<vector<pair<int, int>>> dp(301, vector<pair<int, int>>(301, {0,0}));

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int mx = 0;

            for(int j=300; j>=0; j--)
            {
                int prevL = nums[i] - j;
                int prevG = nums[i] + j;

                int curr = 0;

                if(prevL >= 0)
                {
                    int l = 1 + dp[prevL][j].second;
                    curr = max(curr, l);
                }
                if(prevG <= 300)
                {
                    int l = 1 + dp[prevG][j].second;
                    curr = max(curr, l);
                }

                mx = max(mx, curr);
                dp[nums[i]][j] = {curr, mx};
                ans = max(ans, mx);
            }


        }

        return ans;
    }
};