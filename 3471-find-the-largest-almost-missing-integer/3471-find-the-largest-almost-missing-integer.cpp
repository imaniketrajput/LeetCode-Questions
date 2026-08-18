class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;
        unordered_set<int> st;

        while(j<n)
        {
            if(j-i+1 == k)
            {
                for(int k=i; k<=j; k++)
                {
                    st.insert(nums[k]);
                }
            

                for(int x : st)
                {
                    mp[x]++;
                }

                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        int result = -1;

        for(auto [el, count] : mp)
        {
            if(count == 1 && el > result)
            {
                result = el;
            }
        }

        return result;
    }
};