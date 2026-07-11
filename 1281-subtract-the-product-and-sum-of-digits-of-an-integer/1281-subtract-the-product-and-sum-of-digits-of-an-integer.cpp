class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sam = n;
        int sum = 0;
        int mul = 1;

        while(sam>0)
        {
            int ld = sam % 10;
            sum += ld;
            mul *= ld;
            sam /= 10;
        }

        return mul - sum;
    }
};