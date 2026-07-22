class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        set<int> bad;

        int mini = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(fronts[i] == backs[i])
            {
                bad.insert(fronts[i]);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(bad.find(fronts[i]) == bad.end())
            {
                mini = min (mini, fronts[i]);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(bad.find(backs[i]) == bad.end())
            {
                mini = min(mini, backs[i]);
            }
        }

        if(mini == INT_MAX) return 0;

        return mini;
    }
};