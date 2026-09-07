class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefixSum(n, 0), suffixSum(n, 0);

        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            prefixSum[i] += prefixSum[i-1]+nums[i]; 
        } 

        suffixSum[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--)
        {
            suffixSum[i] += suffixSum[i+1] + nums[i];
        } 

        long long mini = LLONG_MAX;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            long long avg1 = prefixSum[i] / (i+1);
            long long avg2 = 0;

            if(i != n-1)
            {
                avg2 = suffixSum[i+1] / (n-i-1);
            }

            long long val = abs(avg1 - avg2);

            if(val < mini)
            {
                mini = val;
                ans = i;
            }
        }

        return ans;
    }
};