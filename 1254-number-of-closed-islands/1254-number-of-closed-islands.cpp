class Solution {
public:
    int m, n;
    bool DFS(vector<vector<int>>& grid, int r, int c)
    {
        if(r < 0 || r >=m || c < 0 || c >= n)
            return false;

        if(grid[r][c] == 1) return true;

        grid[r][c] = 1;

        bool left_closed = DFS(grid, r, c-1);
        bool right_closed = DFS(grid, r, c+1);
        bool upper_closed = DFS(grid, r-1, c);
        bool lower_closed = DFS(grid, r+1, c);

        return left_closed && right_closed && upper_closed && lower_closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                {
                    if(DFS(grid, i, j))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};