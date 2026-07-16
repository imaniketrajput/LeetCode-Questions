class Solution {
public:
    string finalString(string s) {
        
        int n = s.length();
        string str = "";

        for(char ch : s)
        {
            if(ch == 'i')
            {
                reverse(str.begin(), str.end());
                continue;
            }

            str.push_back(ch);
        }

        return str;
    }
};