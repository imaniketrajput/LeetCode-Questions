class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, list<int>> adj;

        vector<int> indegree(numCourses, 0);

        for(auto& vec: prerequisites)
        {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        vector<int> res;

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }


        while(!q.empty())
        {
            int v = q.front();
            res.push_back(v);
            q.pop();

            for(int &u : adj[v])
            {
                indegree[u]--;

                if(indegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }

        if(numCourses != res.size()) return {};

        return res;
        
    }
};