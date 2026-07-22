class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        int k = 0;
        int i=0, j=1;

        while(k<n){
            
            if(nums[k]&1)
            {
                res[j] = nums[k++];
                j+=2;
            }
            else{
                res[i] = nums[k++];
                i+=2;
            }


        }

        return res;
    }
};