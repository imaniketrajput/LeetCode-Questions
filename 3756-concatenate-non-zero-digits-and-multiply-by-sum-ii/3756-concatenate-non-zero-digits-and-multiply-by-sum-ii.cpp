class Solution {
public:
    
    typedef long long ll;
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = s.length();

        vector<int> nonZeroCount(n, 0);
        vector<ll> numberUpto(n, 0);
        vector<ll> digitSumUpto(n, 0);
        vector<ll> pow10(n+1, 0);

        pow10[0] = 1;
        digitSumUpto[0] = s[0] - '0';
        numberUpto[0] = s[0] - '0';
        nonZeroCount[0] = (s[0] != 0) ? 1 : 0;

        for(int i = 1; i < n; i++)
        {
            pow10[i] = (pow10[i-1] * 10) % MOD;
            
            int digit = s[i] - '0';


            nonZeroCount[i] = nonZeroCount[i-1] + ((digit != 0) ? 1 : 0);

            if(digit != 0)
            {
                numberUpto[i] = ((numberUpto[i-1] * 10) + digit) % MOD;
            }
            else{
                numberUpto[i] = numberUpto[i-1];
            }

            digitSumUpto[i] = digitSumUpto[i-1] + digit;

        }

        int q = queries.size();
        vector<int> result(q);

        for(int i=0; i<q; i++)
        {
            int sIdx = queries[i][0];
            int eIdx = queries[i][1];

            ll sum = digitSumUpto[eIdx] -  ((sIdx==0) ? 0 : digitSumUpto[sIdx-1]);

            int numBefore = (sIdx == 0) ? 0 : numberUpto[sIdx-1];
            int k = nonZeroCount[eIdx] - ((sIdx == 0) ? 0 : nonZeroCount[sIdx-1]);

            ll x = (numberUpto[eIdx] - (numBefore * pow10[k] % MOD) + MOD) % MOD;

            result[i] = (int) ((x*sum) % MOD);
        }

        return result;
        
    }
};