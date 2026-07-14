class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxi = 0;

        for(auto row : accounts)
        {
            maxi = max(maxi, accumulate(row.begin(), row.end(), 0));
        }

        return maxi;
    }
};