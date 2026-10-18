class Solution {
public:
    int n;

    void DFS(unordered_map<int, list<int>> &adj, int u, vector<bool> &visited)
    {
        visited[u] = true;

        for(auto &node : adj[u])
        {
            if(!visited[node])
            {
                visited[node] = true;
                DFS(adj, node, visited);
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
                DFS(adj, i, visited);
                count++;
            }

        }

        return count;

        
    }
};