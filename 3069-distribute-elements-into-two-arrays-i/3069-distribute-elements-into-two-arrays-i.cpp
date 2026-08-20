class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;

        vector<int> result;

        arr1.push_back(nums[0]); // op-1
        arr2.push_back(nums[1]); // op-2

        for(int i=2; i<n; i++)
        {
            if(arr1.back() > arr2.back())
            {
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }

        for(int i=0; i<arr1.size(); i++)
        {
            result.push_back(arr1[i]);
        }

        for(int i=0; i<arr2.size(); i++)
        {
            result.push_back(arr2[i]);
        }

        return result;
    }
};