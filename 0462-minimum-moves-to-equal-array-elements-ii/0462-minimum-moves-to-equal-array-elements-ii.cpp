class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        nth_element(begin(nums), begin(nums)+ n/2, end(nums));

        int median = nums[n/2];
        long long gap = 0;


        for(int i =0; i<n; i++)
        {
            gap += abs(median - nums[i]);
        }

        return gap;
    }
};