class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> comp;
        unordered_set<int> ans;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                comp.insert(nums[i]^nums[j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(auto& val : comp)
            {
                ans.insert(val ^ nums[i]);
            }
        }
        return ans.size();
    }
};