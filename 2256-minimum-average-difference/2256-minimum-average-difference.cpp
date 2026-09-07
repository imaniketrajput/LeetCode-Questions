class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;

        for(int num : nums)
        {
            sum += num;
        }

        long long RS = 0;
        long long LS = 0;

        int result = INT_MAX;
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            LS += nums[i];
            RS = sum - LS;

            int n1 = i+1;
            int n2 = n - n1;

            long long left_avg = LS / n1;
            long long right_avg = (i==n-1) ? 0 : RS / n2;

            int diff = abs(left_avg - right_avg);

            if(diff < result)
            {
                result = diff;
                ans = i;
            }
        }

        return ans;
    }
};