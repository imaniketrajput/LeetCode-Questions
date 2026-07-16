class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = -1;

        vector<int> gcd;

        for(int el : nums)
        {
            maxi = max(maxi, el);

            gcd.push_back(__gcd(maxi, el));
        }

        sort(gcd.begin(), gcd.end());


        int s = gcd.size();
        int i = 0;
        int j = s - 1;
        long long sum = 0;


            
        while(i<j)
        {
            int g = __gcd(gcd[i],gcd[j]);
            sum += g;
            i++;
            j--;
        }



        return sum;

        
    }
};