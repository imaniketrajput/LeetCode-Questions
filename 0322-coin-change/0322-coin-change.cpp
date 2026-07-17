class Solution {
public:

    int solveMem(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0)
            return 0;


        if(dp[amount] != -1) return dp[amount];

        int minCoin = INT_MAX;

        for(int i=0; i<coins.size(); i++)
        {
            int coin = coins[i];

            if(coin <= amount)
            {
                int recursionAns = solveMem(coins, amount-coin, dp);

                if(recursionAns != INT_MAX) 
                {
                    int coinUsed = 1 + recursionAns;
                    minCoin = min(minCoin, coinUsed);
                }
            }
        }

        dp[amount] = minCoin;

        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = solveMem(coins, amount, dp);

        if(ans == INT_MAX) return -1;
        return ans;
    }
};