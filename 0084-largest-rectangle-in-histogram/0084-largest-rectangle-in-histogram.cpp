class Solution {
public:
    void nextGreaterElement(vector<int>& heights, vector<int>& next)
    {
        int n = heights.size();
        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--)
        {
            while(st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            next.push_back(st.top());
            st.push(i);
        }
    }

    void prevGreaterElement(vector<int>& heights, vector<int>& prev)
    {
        int n = heights.size();
        stack<int> st;
        st.push(-1);

        for(int i=0; i<n; i++)
        {
            while(st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            prev.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> next;
        vector<int> prev;

        nextGreaterElement(heights, next);
        reverse(begin(next), end(next));
        for(int i=0; i<next.size(); i++)
        {
            if(next[i] == -1)
            {
                next[i] = next.size();
            }
        }
        prevGreaterElement(heights, prev);

        int maxArea = INT_MIN;
        for(int i=0; i<next.size(); i++)
        {
            int width = next[i] - prev[i] - 1;

            int height = heights[i];

            int currArea = height * width;

            maxArea = max(maxArea, currArea);
        }

        return maxArea;

    }
};