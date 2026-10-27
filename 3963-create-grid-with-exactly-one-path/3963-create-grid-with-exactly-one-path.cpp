class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> Matrix(m, vector<char>(n, '#'));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j == n-1)
                {
                    Matrix[i][j] = '.';
                }
            }
        }

        vector<string> ans;

        for(int i=0; i<m; i++)
        {
            string res;
            for(int j=0; j<n; j++)
            {
                res.push_back(Matrix[i][j]);
            }

            ans.push_back(res);
        }


        return ans;


    }
};