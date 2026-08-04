class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));

        vector<int> res;

        int i = 0, j=mini;

        while(i<n)
        {
            if(nums[i] == j)
            {
                i++;
                j++;
            }
            else{
                res.push_back(j);
                j++;
            }
        }

        
        return res;

    }
};