class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();

        int total = 0;

        for(char ch : s)
        {
            total += ch - 'a' + 1;
        }

        int left = 0;

        for(int i=0; i<n-1; i++)
        {
            left += s[i] - 'a' + 1;

            int right = total - left;

            if(right == left) return true;

        }

        

        return false;
    }
};