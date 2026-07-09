class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);

        int currentComponent = 0;

        for(int i=1; i<n; i++)
        {
            if(nums[i]-nums[i-1] > maxDiff)
            {
                currentComponent++;
            }

            group[i] = currentComponent;
        }

        int q = queries.size();
        vector<bool> result;

        for(int i=0; i<q; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            result.push_back((group[u]==group[v]));
            
        } 

        return result;
    }
};