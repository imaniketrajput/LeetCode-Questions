class Solution {
public:
    int countDigits(int num) {
        
        int count  = 0;
        int ori = num;

        while(num > 0)
        {
            int ld = num % 10;

            if(ori % ld == 0) count++;

            num /= 10;
        }

        return count;
    }
};