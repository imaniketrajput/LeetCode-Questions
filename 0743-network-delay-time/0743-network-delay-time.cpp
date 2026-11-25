class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, list<pair<int, int>>> adj;

        for(vector<int> row : times)
        {
            int u = row[0];
            int v = row[1];
            int w = row[2];

            adj[u].push_back({v,w});
        }

        vector<int> res(n+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        pq.push({0, k});
        res[k] = 0;

        while(!pq.empty())
        {
            pair<int, int> P = pq.top();
            pq.pop();

            int dist = P.first;
            int node = P.second;

            for(auto& nbr : adj[node])
            {
                int padosi = nbr.first;
                int new_dist = nbr.second;

                if(new_dist + dist < res[padosi])
                {
                    res[padosi] = new_dist + dist;
                    pq.push({res[padosi], padosi});
                }
            }
        }

        int mx = -1;

        for(int i=1; i<=n; i++)
        {
            if(res[i] == INT_MAX)
                return -1;

            if(res[i] > mx)
                mx = res[i];
        }

        return mx;


    }
};