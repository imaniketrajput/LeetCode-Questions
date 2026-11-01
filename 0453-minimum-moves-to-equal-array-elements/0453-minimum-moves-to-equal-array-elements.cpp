class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(begin(nums), end(nums));

        int gap = 0;

        for(int i=0; i<n; i++)
        {
            gap += abs(mini - nums[i]);
        }

        return gap;
    }
};
