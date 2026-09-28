class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int maxi = 0;

        for(char ch: s)
        {
            if(ch == '(')
            {
                st.push(ch);
                int s = st.size();
                maxi = max(maxi, s);
                
            }
            else if(ch == ')'){
                st.pop();
            }
            else{
                continue;
            }
        }

        return maxi;
    }
};