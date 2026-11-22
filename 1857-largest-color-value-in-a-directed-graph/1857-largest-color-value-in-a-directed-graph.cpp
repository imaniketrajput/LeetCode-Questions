class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();

        unordered_map<int, list<int>> adj;
        vector<int> indegree(N,0);

        for(vector<int>& row : edges)
        {
            int u = row[0];
            int v = row[1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> que;

        vector<vector<int>> table(N, vector<int>(26, 0));

        for(int i=0; i<N; i++){
            if(indegree[i] == 0)
            {
                que.push(i);
                table[i][colors[i] - 'a'] = 1;
            }
        }

        int answer = 0;
        int countNodes = 0;

        while(!que.empty())
        {
            int u = que.front();
            que.pop();

            countNodes++;

            answer = max(answer, table[u][colors[u] - 'a']);

            for(int &v : adj[u])
            {
                for(int i=0; i<26; i++)
                {
                    table[v][i] = max(table[v][i], table[u][i] + (colors[v] - 'a' == i)); 
                }

                indegree[v]--;

                if(indegree[v] == 0)
                {
                    que.push(v);
                }
            }
        }

        if(countNodes < N)
            return -1;

        return answer;
    }
};