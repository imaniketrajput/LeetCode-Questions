class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        vector<bool> visited(26, false);
        vector<int> lastIdx(26);

        string result = "";

        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            lastIdx[ch-'a'] = i;
        }

        for(int i=0; i<n; i++)
        {
            char ch = s[i];

            int idx = ch - 'a';

            if(visited[idx]==true)
                continue;

            while(result.length()>0 && result.back() > ch && lastIdx[result.back()-'a'] > i)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch-'a'] = true;
        }

        return result;

    }
};