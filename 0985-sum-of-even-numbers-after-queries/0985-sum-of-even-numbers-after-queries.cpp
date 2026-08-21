class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> result;

        for(auto& query : queries)
        {
            int val = query[0];
            int idx = query[1];
            
            nums[idx] += val;

            int sum = 0;

            for(int i=0; i<n; i++)
            {
                if(!(nums[i]&1))
                {
                    sum += nums[i];
                }
            }

            result.push_back(sum);

        }

        return result;
    }
};