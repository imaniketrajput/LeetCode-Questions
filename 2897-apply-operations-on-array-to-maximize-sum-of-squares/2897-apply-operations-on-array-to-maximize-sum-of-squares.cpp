class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {

        long long ans = 0;

        int cnt[31] = {};

        // Count set bits
        for(int x : nums)
        {
            for(int b = 0; b < 31; b++)
            {
                if(x & (1 << b))
                    cnt[b]++;
            }
        }

        // Construct k largest numbers
        for(int i = 0; i < k; i++)
        {
            long long x = 0;

            for(int b = 30; b >= 0; b--)
            {
                if(cnt[b] > 0)
                {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};