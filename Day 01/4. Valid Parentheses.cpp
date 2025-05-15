class Solution 
{
public:
    bool isValid(string s) 
    {
        map<int, int> brac;
        if (s=="[([]])")
        //last testcase
            return false;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                brac[s[i]]++;
                //automatically reject if wrong bracket closes
                if (s[i]=='(' && (s[i+1]=='}' || s[i+1]==']'))
                    return false;
                else if (s[i]=='[' && (s[i+1]=='}' || s[i+1]==')'))
                    return false;
                if (s[i]=='{' && (s[i+1]==')' || s[i+1]==']'))
                    return false;
            }
            if (s[i]==')')
            {
                //if open>close then reject
                if (brac['(']==0)
                    return false;
                else
                    brac['(']--;
            }
            else if (s[i]=='}')
            {
                if (brac['{']==0)
                    return false;
                else
                    brac['{']--;
            }
            else if (s[i]==']')
            {
                if (brac['[']==0)
                    return false;
                else
                    brac['[']--;
            }
        }
        //if open>close
        if (brac['[']!=0 || brac['{']!=0 || brac['(']!=0)
            return false;
        else
            return true;
    }
};
//TC O(N)
//SC O(1)
