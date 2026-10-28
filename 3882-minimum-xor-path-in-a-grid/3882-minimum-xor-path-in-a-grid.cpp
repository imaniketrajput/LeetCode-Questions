// class Solution {
// public:
//     int m, n;
//     int solve(vector<vector<int>>& grid, int i, int j, int currXor, vector<<vector<int>> &dp)
//     {

//         if(i >= m || j >= n)
//         {
//             return 0;
//         }

//         currXor ^= grid[i][j];

//         if(i==m-1 && j == n-1)
//         {
//             return currXor;
//         }

//         if(dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }

//         int right = solve(grid, i, j+1, currXor);
//         int down = solve(grid, i+1, j, currXor);

//         return dp[i][j] = min(right, down);
//     }
//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         vector<<vector<int>> dp(m, vector<int>(n, -1));
//         int ans  = 0;
//         return solve(grid, 0, 0, ans, dp);
        
//     }
// };

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        //m*n
        //dp[i][j] = it stores a bitset<1024> {0, 0, 1, 1, 0, .....}

        dp[0][0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;

                bitset<1024> up; //[i-1][j]
                bitset<1024> left; //[i][j-1]

                if(i > 0) {
                    up = dp[i-1][j];
                }
                if(j > 0) {
                    left = dp[i][j-1];
                }

                bitset<1024> combined = up | left; //OR operation

                for(int xorVal = 0; xorVal < 1024; xorVal++) {
                    if(combined[xorVal]) {
                        int resultXorVal = xorVal ^ grid[i][j];
                        dp[i][j][resultXorVal] = 1;
                    }
                }
            }
        }

        //dp[m-1][n-1]
        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(dp[m-1][n-1][xorVal]) {
                return xorVal;
            }
        }

        return -1;

        
    }
};