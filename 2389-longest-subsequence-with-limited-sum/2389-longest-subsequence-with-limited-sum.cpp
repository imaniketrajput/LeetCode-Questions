class Solution {
public:

    int binarySearch(vector<int>& nums, int n, int target)
    {
        int l = 0;
        int r  = n-1;

        int resultIdx = -1;

        while(l<=r)
        {
            int mid = (l+r) >> 1;

            if(nums[mid] <= target) // {1,3, 7, 12}
            {
                resultIdx = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }

        return resultIdx+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i=1; i<n; i++)
        {
            nums[i] += nums[i-1];
        }

        vector<int> ans;

        for(int &query : queries)
        {
            int count = binarySearch(nums, n, query);

            ans.push_back(count);
        }

        return ans;
    }
};