class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int m = 1 << n;
        // Precompute LCM for each subset (skip empty subset)
        vector<long long> lcmVal(m, 0);
        for (int mask = 1; mask < m; mask++) {
            long long l = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l = lcm(l, (long long)coins[i]);
                    if (l > (long long)4e18) { l = -1; break; } // overflow guard
                }
            }
            lcmVal[mask] = l;
        }
        
        auto countLE = [&](long long x) -> long long {
            long long count = 0;
            for (int mask = 1; mask < m; mask++) {
                int bits = __builtin_popcount(mask);
                long long l = lcmVal[mask];
                if (l <= 0) continue; // overflow or invalid, contributes ~0 for reasonable x
                long long cnt = x / l;
                if (bits % 2 == 1) count += cnt;
                else count -= cnt;
            }
            return count;
        };
        
        long long lo = 1, hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    
    long long gcd(long long a, long long b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};