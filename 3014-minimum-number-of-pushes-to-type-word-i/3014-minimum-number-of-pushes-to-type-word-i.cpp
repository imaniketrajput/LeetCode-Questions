class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;

        unordered_map<int, int> mp;

        int asign_key = 2;

        for(char ch : word)
        {
            if(asign_key > 9)
            {
                asign_key = 2;
            }

            mp[asign_key]++;
            result += mp[asign_key];

            asign_key++;
        }

        return result;
    }
};