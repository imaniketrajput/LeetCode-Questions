class Solution {
public:
    
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int n = nums.size();

        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> divisorFreq(maxVal+1, 0);

        for(int i=0; i<n; i++)
        {
            int num = nums[i];

            for(int j=1; j*j <= num; j++)
            {
                if(num % j == 0)
                {
                    divisorFreq[j]++;
                

                    if(num/j != j)
                    {
                        divisorFreq[num/j]++;
                    }
                }
            }
        }


        vector<long long> pairWithGcd(maxVal+1, 0);

        for(int g=maxVal; g>=1; g--)
        {
            long long count = divisorFreq[g];

            //nC2
            pairWithGcd[g] = count * (count-1) / 2;

            //Correction Time
            for(int mult=2*g; mult<=maxVal; mult+=g)
            {
                pairWithGcd[g] -= pairWithGcd[mult];
            }
        }

        vector<long long> prefixCountGcd(maxVal+1, 0);

        for(int g=1; g<=maxVal; g++)
        {
            prefixCountGcd[g] = prefixCountGcd[g-1] + pairWithGcd[g];
        }

        vector<int> result;

        for(long long idx : queries){

            int l = 1;
            int h = maxVal;
            int temp = 1;

            while(l<=h){
                int mid_gcd = (l+h) >> 1;

                if(prefixCountGcd[mid_gcd] > idx)
                {
                    temp = mid_gcd;
                    h = mid_gcd - 1;
                }
                else{
                    l = mid_gcd + 1;
                }
            }

            result.push_back(temp);
        }


        return result;

    }
};