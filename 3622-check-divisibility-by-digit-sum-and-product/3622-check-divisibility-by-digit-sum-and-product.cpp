class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum = 0;
        int pro = 1;

        int ori = n;

        while(n > 0)
        {
            int ld  = n % 10;

            sum += ld;
            pro *= ld;

            n /= 10;
        }

        int totalSum = sum + pro;


        return (ori % totalSum == 0);
    }
};