class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> result;

        for(int ball=0; ball < n; ball++)
        {
            int row = 0;
            int col = ball;
            
            bool atkka = true;

            while(row < m && col < n)
            {
                if(grid[row][col] == 1)
                {
                    if(col == n-1 || grid[row][col+1] == -1)
                    {
                        atkka = false;
                        break;
                    }
                    col++;
                }
                else{
                    if(col == 0 || grid[row][col-1] == 1)
                    {
                        atkka = false;
                        break;
                    }
                    col--;
                }

                row++;
            }

            if(atkka) result.push_back(col);
            else result.push_back(-1);
        }

        return result;
    }
};