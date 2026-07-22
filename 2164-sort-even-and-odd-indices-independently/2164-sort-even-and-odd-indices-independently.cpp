class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> odd;
        vector<int> even;

        for(int i=0; i<n; i++)
        {
            if(i&1)
            {
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }

        sort(begin(even), end(even));
        sort(begin(odd), end(odd), greater<int>());

        vector<int> result;
        int e = 0, o = 0;

        for(int k=0; k<n; k++)
        {
            if(k&1)
            {
                result.push_back(odd[o++]);
            }
            else{
                result.push_back(even[e++]);
            }
        }

        return result;
    }
};