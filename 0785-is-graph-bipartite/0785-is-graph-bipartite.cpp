class Solution {
public:
    int n;

    bool DFS(vector<vector<int>>& graph, int curr, vector<int> &color, int currColor)
    {
        color[curr] = currColor;

        for(int &v : graph[curr])
        {
            if(color[v] == currColor)
                return false;

            if(color[v] == -1)
            {
                int colorOfV = 1 - currColor;

                if(DFS(graph, v, color, colorOfV) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();

        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(DFS(graph, i, color, 0) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};