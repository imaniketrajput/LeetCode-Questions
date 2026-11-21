class Solution {
public:

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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;


        DFS(node1, edges, dist1, visited1);
        DFS(node2, edges, dist2, visited2);

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