class Solution {
public:

    int n;

    int edgeScore(vector<int>& edges) {
        n = edges.size();

        queue<int> que;
        vector<long long> indegree(n, 0);

        for(int i=0; i<n; i++)
        {
            int v = edges[i];
            indegree[v] += i;
        }

        int ans = -1;

        long long maxEdgeSum = -1;

        for(int i=0; i<n; i++)
        {
            if(indegree[i] > maxEdgeSum)
            {
                maxEdgeSum = indegree[i];
                ans = i;
            }
        }

        return ans;



    }
};