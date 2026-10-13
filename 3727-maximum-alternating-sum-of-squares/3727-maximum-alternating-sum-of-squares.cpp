class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0) nums[i] *= -1;
        }

        sort(nums.begin(), nums.end());

        long long total = 0;

        int l = 0;
        int r = n-1;

        while(l<r)
        {
            total += nums[r] * nums[r];
            r--;
            total -= nums[l] * nums[l];
            l++;

        }

        if(l==r)
        {
            total += nums[r] * nums[r];
        }

        return total;
    }
};