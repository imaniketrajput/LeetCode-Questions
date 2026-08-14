class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        int result = 0;

        while(j<n)
        {
            mp[s[j]]++;

            while(i<j && mp[s[j]] > 2)
            {
                mp[s[i]]--;
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }
};