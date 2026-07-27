class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;

        for(int num : nums){
            if(max1 < num){
                max2 = max1;
                max1 = num;
            }
            else if(num > max2){
                max2 = num;
            }
        }

        int ans = (max1-1) * (max2-1);
        return ans;
    }
};