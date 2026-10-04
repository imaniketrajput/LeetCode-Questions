class Solution {
public:

    int dp[101][101];
    bool solve(int idx, int open, string& s, int n)
    {
        if(idx == n) return open == 0;
        
        if(dp[idx][open] != -1)
        {
            return dp[idx][open];
        }

        bool isValid = false;

        if(s[idx] == '*')
        {
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);

            if(open > 0)
            {
                isValid |= solve(idx+1, open-1, s, n);
            }
        }
        else if(s[idx] == '(')
        {
            isValid |= solve(idx+1, open+1, s, n);
        }
        else if(open > 0)
        {
            isValid |= solve(idx+1, open-1, s, n);
        }

        return dp[idx][open] = isValid;

    }

    bool checkValidString(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s, n);
    }
};