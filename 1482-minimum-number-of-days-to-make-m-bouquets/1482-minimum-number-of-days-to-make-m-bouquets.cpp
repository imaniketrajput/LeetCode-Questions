class Solution {
public:

    bool canWeMakeBouquets(vector<int>& bloomDay, int m, int k, int day){
        
        int counter = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day){
                counter++;
            }
            else{
                counter = 0;
            }

            if(counter == k)
            {
                m--;
                counter = 0;
                if(m == 0) return true;
            }

        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long int requirement = (long long) m * (long long) k;
        if(bloomDay.size() < requirement) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;

        while(l <= h)
        {
            int mid = (l + h) >> 1;
            int day = mid;

            if(canWeMakeBouquets(bloomDay, m, k, day))
            {
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};