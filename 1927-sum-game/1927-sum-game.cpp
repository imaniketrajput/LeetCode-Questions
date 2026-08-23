class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int leftSum = 0;
        int rightSum = 0;

        int leftMarkCount = 0;
        int rightMarkCount = 0;

        for(int i=0; i<n; i++)
        {
            if(num[i] == '?')
            {
                if(i < n/2)
                {
                    leftMarkCount++;
                }
                else{
                    rightMarkCount++;
                }
            }
            else{
                if(i < n/2)
                {
                    leftSum += num[i] - '0';
                }
                else{
                    rightSum += num[i] - '0';
                }
            }
        }

        int totalMarkCount = leftMarkCount + rightMarkCount;

        if(totalMarkCount&1) return true;

        int LEFT = 2 * leftSum + 9 * leftMarkCount;
        int RIGHT = 2 * rightSum + 9 * rightMarkCount;

        if(LEFT == RIGHT)
        {
            return false;
        }

        return true;
    }
};