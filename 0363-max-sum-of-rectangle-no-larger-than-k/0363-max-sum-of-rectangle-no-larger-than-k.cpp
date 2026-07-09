class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int res = INT_MIN;

        for(int l=0; l<col; l++)
        {
            vector<int> sums(row);

            for(int r=l; r<col; r++)
            {
                for(int i=0; i<row; i++){
                    sums[i] += matrix[i][r];
                }    
                set<int> s = {0};
                int run_sum = 0;

                    for(auto& sum : sums)
                    {
                        run_sum += sum;

                        auto it = s.lower_bound(run_sum - k);

                        if(it != end(s))
                            res = max(res, run_sum - *it);

                        s.insert(run_sum);
                    }

            }
        }

        return res;
    }
};