class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int row = grid.size();
        int col = grid[0].size();

        int totalEle = row * col;

        k = k % totalEle;

        vector<vector<int>> ans(row, vector<int>(col));
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
               
               int currIdx = i * col + j;
               int nextIdx = (currIdx + k) % totalEle;

               ans[nextIdx/col][nextIdx % col] = grid[i][j];

                
                
            }
        }

        return ans;
    }
};