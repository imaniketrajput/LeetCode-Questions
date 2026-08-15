class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int, int> mp;
        int idx = 1;
        for(int i=0; i<n; i++)
        {
            int rem = target - numbers[i];

            if(mp.count(rem) != 0)
            {
                return {mp[rem], idx};
            }
            else{
                mp.insert({numbers[i], idx++});
            }
        }

        return {};
    }
};