class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        int s = words.size();

        vector<int> res;

        for(int i=0; i<s; i++)
        {
            string str = words[i];

            if(str.find(x) != string::npos)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};