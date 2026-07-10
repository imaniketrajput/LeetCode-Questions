class Solution {
public:

    void LastOccurenceIdx(vector<int>& nums, int target, int n, vector<int>& ans)
    {
        int l = 0;
        int h = n-1;

        int a = -1;

        while(l<=h)
        {
            int mid = l + (h-l) / 2;

            if(nums[mid] == target)
            {
                a = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        ans[1] = a;
    }

    void firstOccuranceIdx(vector<int>& nums, int target, int n, vector<int>& ans)
    {
        int l = 0;
        int h = n-1;

        int a = -1;

        while(l<=h)
        {
            int mid = l + (h-l) / 2;

            if(nums[mid] == target)
            {
                a = mid;
                h = mid - 1;
            }
            else if(nums[mid] > target)
            {
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        ans[0] = a;
    }




    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        int l = 0;
        int h = n-1;

        vector<int> ans(2);

        firstOccuranceIdx(nums, target, n, ans);
        LastOccurenceIdx(nums, target, n, ans);

        return ans;
    }
};