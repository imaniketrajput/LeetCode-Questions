class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<int> st;

        for(char ch : s)
        {
            if(ch == '(')
            {
                st.push(ch);
            }
            else{
                if(!st.empty())
                {
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }

        return count + st.size();
    }
};