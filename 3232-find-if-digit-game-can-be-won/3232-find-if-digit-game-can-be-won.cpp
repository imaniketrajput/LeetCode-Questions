class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int s1 = 0;
        int s2 = 0;

        for(int el : nums)
        {
            if(el < 10) s1+= el;
            else s2+=el;
        }

        return !(s1==s2);

    }
};