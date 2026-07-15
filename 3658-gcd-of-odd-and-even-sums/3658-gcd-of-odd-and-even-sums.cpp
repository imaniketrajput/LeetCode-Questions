class Solution {
public:

    int GCD(int sum1, int sum2)
    {
        while(sum2 != 0)
        {
            int temp = sum2;
            sum2 = sum1 % sum2;
            sum1 = temp; 
        }

        return sum1;

    }

    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n * (n+1);

        int ans = GCD(sumOdd, sumEven);

        return ans;
    }
};