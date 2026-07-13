class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0;
        int h = n-1;

        while(l<=h)
        {
            int mid = l + (h-l) / 2;

            if(l==h) return nums[l];

            int currValue = nums[mid];
            int leftValue = -1;
            if(mid-1 >= 0)
            {
                leftValue = nums[mid-1];
            }

            int rightValue = -1;
            if(mid+1 < n)
            {
                rightValue = nums[mid+1];
            }


            if(currValue != leftValue && currValue != rightValue)
            {
                return currValue;
            }

            if(currValue==leftValue && currValue != rightValue)
            {
                int pairfirstIdx = mid-1;

                if(pairfirstIdx & 1)
                {
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else if(currValue!=leftValue && currValue == rightValue)
            {
                int pairfirstIdx = mid;

                if(pairfirstIdx & 1)
                {
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};