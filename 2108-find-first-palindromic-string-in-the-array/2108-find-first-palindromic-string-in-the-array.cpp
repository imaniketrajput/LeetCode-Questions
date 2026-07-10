class Solution {
public:

    string firstPalindrome(vector<string>& words) {        
        
        int s = words.size();

        for(string word : words)
        {
            string ori = word;

            int w = ori.length();
            int l = 0;
            int r = w-1;

            while(l<=r)
            {
                swap(ori[l], ori[r]);
                l++;
                r--;

            }

            if(word == ori)
            {
                return word;
            }
        }

        return "";

    }
};