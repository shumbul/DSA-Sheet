class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.size()!=t.size())
            return false;
        for (int i=0;i<s.size();i++)
        {
            for (int j=0;j<s.size();j++)
            {
                if (s[i]==s[j])
                {
                    if (t[i]!=t[j])
                        return false;
                }
                if (t[i]==t[j])
                {
                    if (s[i]!=s[j])
                        return false;
                }
            }
        }
        return true;
    }
};
//TC O(N^2)
//SCO(1)
