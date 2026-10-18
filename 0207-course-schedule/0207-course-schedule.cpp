class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, list<int>> adj;

        for(auto &vec : prerequisites) 
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        queue<int> q;
        vector<int> indegree(numCourses, 0);

        for(int u=0; u<numCourses; u++)
        {
            for(int v : adj[u])
            {
                indegree[v]++;
            }
        }

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty())
        {
            int u = q.front();
            count++;
            q.pop();

            for(int &v : adj[u])
            {
                indegree[v]--;

                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }

        }


        return count == numCourses;
    }
};