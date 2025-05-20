class Solution 
{
public:
    int maximumLength(string s) 
    {
        map<string, int> freq;
        string special="";
        int len=0;
        for (int i=0;i<s.size();i++)
        {
            for (int j=i;j<s.size() && s[i]==s[j];j++)
            //j increases the length of substring
            {
                string temp=s.substr(i, j-i+1); //length should start from 1 i.e. second idx-first idx+1
                freq[temp]++;
            }
            
        }
        for (auto val:freq)
        {
            if (val.second>=3)
            {
                if (len<val.first.size())
                {
                    len=max(len, (int)val.first.size());
                }
            }
        }
        if (len>0)
            return len;
        return -1;
    }
};
