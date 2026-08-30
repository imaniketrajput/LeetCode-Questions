class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(nums.begin(), nums.end()) - begin(nums);
        int maxElIdx = max_element(nums.begin(), nums.end()) - begin(nums);

        int leftIdx = min(minElIdx, maxElIdx);
        int rightIdx = max(minElIdx, maxElIdx);

        return min({leftIdx+1+n-rightIdx, rightIdx+1, n-leftIdx});
    }
};