class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, list<int> > adj;
        vector<bool> suspicious(n, false);
        vector<int> inDegree(n,0);

        for(auto& edges : invocations)
        {
            int u = edges[0];
            int v = edges[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;

        q.push(k);
        suspicious[k] = true;

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(auto &ngbr: adj[top])
            {
                inDegree[ngbr]--;

                if(!suspicious[ngbr])
                {
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for(int i=0; i<n; i++)
        {
            if(suspicious[i] && inDegree[i]>0)
            {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i])
                result.push_back(i);
        }

        if(cannotRemove)
        {
            vector<int> vec;
            for(int i=0; i<n; i++)
            {
                vec.push_back(i);
            }

            return vec;
        }

        return result;
    }
};