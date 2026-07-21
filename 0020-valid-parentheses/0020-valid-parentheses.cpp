class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(char ch : str)
        {
            if(ch == '(' || ch=='{' || ch == '[')
            {
                st.push(ch);
            }
            else{
                if(ch==')' && !st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else if(ch=='}' && !st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else if(ch==']' && !st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(!st.empty()) return false;

        return true;
    }
};