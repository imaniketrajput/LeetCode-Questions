class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int c =0;

        for(int el : nums)
        {
            if(el == 0) return 0;

            if(el < 0) c++;
        }

        if(c&1) return -1;
        else return 1;
    }
};