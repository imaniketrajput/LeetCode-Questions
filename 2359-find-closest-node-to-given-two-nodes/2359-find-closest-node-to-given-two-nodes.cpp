class Solution {
public:

    int n;

    void DFS(int node, vector<int>& edges, vector<int>& dist, vector<bool>& visited)
    {
        visited[node] = true;

        int v = edges[node];

        if(v != -1 && !visited[v])
        {
            visited[v] = true;
            dist[v] = 1 + dist[node];
            DFS(v, edges, dist, visited);
        }
    }

    void BFS(int node, vector<int>& edges, vector<int>& dist)
    {
        queue<int> q;

        dist[node] = 0;
        vector<bool> visited(n, false);
        q.push(node);
        visited[node] = true;

        int v = edges[node];

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            int v = edges[u];

            if(v != -1 && !visited[v])
            {
                visited[v] = true;
                dist[v] = 1 + dist[u];
                q.push(v);

            }

        }
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        BFS(node1, edges, dist1);
        BFS(node2, edges, dist2);

        int minDistNode = -1;
        int minDistTillNow = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int mxD = max(dist1[i], dist2[i]);

            if(minDistTillNow > mxD)
            {
                minDistTillNow = mxD;
                minDistNode = i;
            }
        }

        return minDistNode;


    }
};