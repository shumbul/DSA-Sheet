class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) 
            return "";
        queue<char> q1, q2;
        // Initialize q1 with first string
        for (char c : strs[0])
            q1.push(c);
        // Loop through the rest of the strings
        for (int i = 1; i < strs.size(); i++) 
        {
            int j = 0;
            // Compare characters in q1 and strs[i]
            while (!q1.empty() && j < strs[i].size()) 
            {
                if (q1.front() == strs[i][j]) 
                {
                    q2.push(q1.front());
                } 
                else 
                {
                    break;
                }
                q1.pop();
                j++;
            }
            // Clear q1 and move q2 to q1 for next iteration
            while (!q1.empty()) 
            {
                q1.pop();
            }
            while (!q2.empty()) 
            {
                q1.push(q2.front());
                q2.pop();
            }
            // If at any point, q1 is empty, return ""
            if (q1.empty())
                return "";
        }
        // Convert q1 to string as final answer
        string result = "";
        while (!q1.empty()) 
        {
            result += q1.front();
            q1.pop();
        }
        return result;
    }
};
