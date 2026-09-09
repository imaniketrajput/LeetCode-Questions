class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<int> ans;

        for(int i=0; i<queries.size(); i++)
        {
            int len = 0;
            int sum = 0;

            for(int j=0; j<n; j++)
            {
                if(sum+nums[j] <= queries[i])
                {
                    sum += nums[j];
                    len++;
                }
                else{
                    break;
                }
                
            }

            ans.push_back(len);
        }

        return ans;
    }
};