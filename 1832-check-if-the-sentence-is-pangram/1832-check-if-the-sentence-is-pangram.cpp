class Solution {
public:
    bool checkIfPangram(string sentence) {
        int len = sentence.length();

        if(len < 26) return false;

        unordered_map<char, int> mp;

        for(char i='a'; i<='z'; i++)
        {
            if(!sentence.contains(i))
            {
                return false;
            }
        }

        return true;
    }
};