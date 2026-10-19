class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;

        int count = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < target)
            {
                count++;
            }
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == target)
            {
                res.push_back(count++);
            }
        }

        return res;
    }
};