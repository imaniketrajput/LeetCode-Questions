class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(vector<int>& row: edges)
        {
            int u = row[0];
            int v = row[1];
            int w = row[2];

            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> row) {
        int u = row[0];
        int v = row[1];
        int w = row[2];

        adj[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int> res(N+1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        res[node1] = 0;

        pq.push({0, node1});

        while(!pq.empty())
        {
            pair<int, int> P = pq.top();
            pq.pop();

            int duri = P.first;
            int node = P.second;

            for(auto& nbr : adj[node])
            {
                int padosi = nbr.first;
                int nayi_duri = duri + nbr.second;

                if(nayi_duri < res[padosi])
                {
                    res[padosi] = nayi_duri;
                    pq.push({nayi_duri, padosi});

                }
            }
        }


        return res[node2]==INT_MAX ? -1 : res[node2];



    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */