class Solution {
public:
    int getLucky(string s, int k) {
        
        int num = 0;

        for(char ch : s)
        {
            int x = ch - 'a' + 1;

            while(x>0)
            {
                num += x % 10;
                x /= 10;
            }
        }

        while(--k){
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }

        return num;

    }
};