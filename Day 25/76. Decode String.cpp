class Solution 
{
    stack<char> words;
    string ans="";
    string value="";
public:
    string decodeString(string s) 
    {
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==']')
            {
                string str="";
                while (!words.empty() && words.top()!='[')
                {
                    str+=words.top(); //form the string
                    words.pop();
                }
                reverse(str.begin(), str.end());
                if (!words.empty() && words.top()=='[')
                {
                    words.pop(); //remove [
                    while (!words.empty() && isdigit(words.top()))
                    {
                        value.push_back(words.top()); //form the number
                        words.pop();
                    }
                }
                reverse(value.begin(), value.end());
                for (int i=0;i<stoll(value);i++)
                {
                    for (int j=0;j<str.size();j++)
                    {
                        words.push(str[j]); //each repeated string's character is pushed back onto the stack because decoding may still be ongoing
                    }
                }
                //words.push(temp);
                value=""; //reset for next pattern
                str="";
            }
            else
                words.push(s[i]);
        }
        while (!words.empty())
        {
            ans=words.top()+ans; //form the full result
            words.pop();
        }
        return ans;
    }
};
//TC O(NK)
//SC O(N)
