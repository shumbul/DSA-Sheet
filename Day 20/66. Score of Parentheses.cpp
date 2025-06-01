class Solution 
{
public:
    int scoreOfParentheses(string s) 
    {
        stack<int> values;
        for (char c : s) 
        {
            if (c == '(') 
            {
                values.push(-1); // marker for '('
            } 
            else 
            {
                if (values.top() == -1) 
                {
                    values.pop();         // pop the '('
                    values.push(1);       // replace '()' with 1
                } 
                else 
                {
                    int sum = 0;
                    while (!values.empty() && values.top() != -1) 
                    {
                        sum += values.top();
                        values.pop();
                    }
                    values.pop();            // pop the '('
                    values.push(2 * sum);    // double the inner score
                }
            }
        }
        // Sum up everything left in the stack
        int result = 0;
        while (!values.empty()) 
        {
            result += values.top();
            values.pop();
        }
        return result;
    }
};
