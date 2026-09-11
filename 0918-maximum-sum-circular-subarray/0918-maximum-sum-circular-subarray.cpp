class Solution {
public:
    int kadensMin(vector<int>& nums, int n)
    {
        int sum = nums[0];
        int minSum = nums[0];

        for(int i=1; i<n; i++)
        {
            sum = min(sum+nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int kadensMax(vector<int>& nums, int n)
    {
        int sum = nums[0];
        int maxSum = nums[0];

        for(int i=1; i<n; i++)
        {
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;

        for(int num : nums)
        {
            totalSum += num;
        }

        int minSum = kadensMin(nums, n);
        int maxSum = kadensMax(nums, n);

        int circular_sum = totalSum - minSum;

        if(maxSum > 0){
            return max(maxSum, circular_sum);
        }

        return maxSum;


    }
};