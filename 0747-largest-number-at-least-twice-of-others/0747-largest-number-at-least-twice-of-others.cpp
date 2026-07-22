class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(begin(nums), end(nums));
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            if(mx == nums[i])
            {
                ans = i;
            }
  
        }

        for(int i=0; i<n; i++)
        {
            if(mx == nums[i]) continue;

            if(mx < 2*nums[i]) return -1;
        }

        return ans;
    }
};