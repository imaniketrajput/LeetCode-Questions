class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for(char ch : s)
        {
            st.push(ch);
        }
        int i = 0;

        while(!st.empty() && i<s.size())
        {
            s[i++] = st.top();
            st.pop();

        }

    }
};