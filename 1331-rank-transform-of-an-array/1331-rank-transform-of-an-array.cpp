class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> dup = arr;

        unordered_map<int , int> mp;

        sort(arr.begin(), arr.end());
        int rank = 1;
        for(int i=0; i<n; i++)
        {
            if(!mp.contains(arr[i]))
            {
                mp[arr[i]] = rank;
                rank++;
            }
    
        }

        vector<int> res;

        for(int i=0; i<n; i++)
        {
            res.push_back(mp[dup[i]]);
        }

        return res;
    }
};