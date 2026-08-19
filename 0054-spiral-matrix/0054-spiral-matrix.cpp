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

        while(count < total)
        {
            if(count < total)
            {
                for(int i=left; i<=right; i++)
                {
                    res.push_back(matrix[top][i]);
                    count++;
                }

                top++;
            }

            if(count < total)
            {
                for(int i=top; i<=bottom; i++)
                {
                    res.push_back(matrix[i][right]);
                    count++;
                }

                right--;
            }

            if(count < total)
            {
                for(int i=right; i>=left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                    count++;
                }

                bottom--;
            }

            if(count < total)
            {

                for(int i=bottom; i>=top; i--)
                {
                    res.push_back(matrix[i][left]);
                    count++;
                }

                left++;
            }

        }

        return res;
    }


};