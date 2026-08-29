class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);

        for (int l = 0; l < n; ) {

            int r = l;

            while (r + 1 < n &&
                   v[r + 1].first - v[r].first <= limit) {
                r++;
            }

            vector<int> idx;
            for (int i = l; i <= r; i++) {
                idx.push_back(v[i].second);
            }

            sort(idx.begin(), idx.end());

            for (int i = 0; i < idx.size(); i++) {
                ans[idx[i]] = v[l + i].first;
            }

            l = r + 1;
        }

        return ans;
    }
};