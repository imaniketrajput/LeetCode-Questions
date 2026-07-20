class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> record;

        for(string str : operations)
        {
            if(str == "+"){
                int first = record.top();
                record.pop();

                int second = record.top();
                record.push(first);
                record.push(first+second);
            }
            else if(str == "D")
            {
                record.push(2*record.top());
            }
            else if(str == "C")
            {
                record.pop();
            }
            else{
                record.push(stoi(str));
            }

        }

        int sum =0;

        while(!record.empty())
        {
            sum += record.top();
            record.pop();
        }

        return sum;
    }
};