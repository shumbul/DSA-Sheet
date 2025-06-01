class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> word;
        string ans="";
        word.push(s[0]);
        for (int i=1;i<s.size();i++)
        {  
            if (word.size()!=0 && word.top()==s[i]) //duplicate found
            {
                word.pop();
            }
            else
                word.push(s[i]);
        }
        while (!word.empty()) //stack is in reverse order
        {
            ans+=word.top();
            word.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//TC O(N)
//SC O(N)
