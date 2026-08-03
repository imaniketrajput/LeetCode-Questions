class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& stoneValue, int i, vector<int>& dp)
    {
        if(i>= n) return 0;

        if(dp[i] != -1) return dp[i];

        int result = stoneValue[i] - solve(stoneValue, i+1, dp);

        if(i+2<=n)
            result = max(result, stoneValue[i] + stoneValue[i+1] - solve(stoneValue, i+2, dp));
        if(i+3<=n)
            result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, i+3, dp));

        dp[i] = result;


        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n+1, -1);

        int score = solve(stoneValue, 0, dp);

        if(score > 0) return "Alice";
        else if(score < 0) return "Bob";
        else return "Tie";
    }
};