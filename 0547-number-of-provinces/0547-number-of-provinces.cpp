class Solution {
public:
    int n;

    void BFS(unordered_map<int, list<int>> &adj, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            for(int v : adj[f])
            {
                if(!visited[v])
                {
                    BFS(adj, v, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        unordered_map<int, list<int>> adj;

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                BFS(adj, i, visited);
                count++;
            }

        }

        return count;

        
    }
};