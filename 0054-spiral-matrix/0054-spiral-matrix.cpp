class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};

        int m = matrix.size();
        int n = matrix[0].size();

        int total = m * n;

        int count = 0;

        int top = 0;
        int bottom = m-1;

        int left = 0;
        int right = n-1;

        vector<int> res;

        int id = 0;

        while(top <= bottom && left <= right)
        {
            if(id == 0)
            {
                for(int i=left; i<=right; i++)
                {
                    res.push_back(matrix[top][i]);
                    count++;
                }

                top++;
            }

            if(id == 1)
            {
                for(int i=top; i<=bottom; i++)
                {
                    res.push_back(matrix[i][right]);
                    count++;
                }

                right--;
            }

            if(id == 2)
            {
                for(int i=right; i>=left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                    count++;
                }

                bottom--;
            }

            if(id == 3)
            {

                for(int i=bottom; i>=top; i--)
                {
                    res.push_back(matrix[i][left]);
                    count++;
                }

                left++;
            }

            id = (id+1)%4;

        }

        return res;
    }


};