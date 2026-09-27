class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> lastSkiplength;

        string result = "";

        for(char ch : s)
        {
            if( ch == '(')
            {
                lastSkiplength.push(result.length());
            }
            else if(ch == ')'){
                int l = lastSkiplength.top();
                lastSkiplength.pop();
                reverse(result.begin()+l, result.end());
            }
            else{
                result.push_back(ch);
            }
        }


        return result;
        
    }
};