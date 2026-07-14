class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int counter = 0;

        for(int el : arr)
        {
            if(el & 1)
            {
                counter++;
            }
            else{
                counter = 0;
            }

            if(counter == 3) return true;
        }

        return false;
    }
};