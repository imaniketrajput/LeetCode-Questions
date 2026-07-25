class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;

        while(n>0)
        {
            int ld = n % 10;
            v.push_back(ld);
            n /= 10;
        }

        int x = v.size();

        sort(v.begin(), v.end());

        return v[x-1] * v[x-2];
    }
};