class Solution {
public:

    bool DFS(unordered_map<int, list<int>> &adj, int u, vector<bool> &visited, vector<int> &inRecursion)
    {
        inRecursion[u] = true;
        visited[u] = true;

        for(int &v: adj[u])
        {
            if(!visited[v])
            {
                if(DFS(adj, v, visited, inRecursion))
                    return true;
            }
            else if(inRecursion[v]){
                return true;
            }
        }

        inRecursion[u] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, list<int>> adj;

        for(auto &vec : prerequisites) 
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        vector<int> inRecursion(numCourses, false);

        vector<bool> visited(numCourses, false);

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i] && DFS(adj, i, visited, inRecursion))
            {
                return false;
            }
        }

        return true;
    }
};