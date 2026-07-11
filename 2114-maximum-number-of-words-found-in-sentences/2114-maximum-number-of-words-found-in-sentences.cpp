class Solution {
public:
    
    int countWord(string str)
    {
        int countSpaces = 0;

        for(char ch : str)
        {
            if(ch == ' ')
            {
                countSpaces++;
            }

        }

        return countSpaces + 1;
    }
    int mostWordsFound(vector<string>& sentences) {
        
        int ans = -1;
        for(string str: sentences)
        {
            ans = max(ans, countWord(str));
        }

        return ans;
    }
};