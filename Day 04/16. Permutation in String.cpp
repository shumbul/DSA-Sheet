class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        sort(s1.begin(), s1.end());
      //O(mlogm)
        for (int i=0;i<s2.size();i++)
        //O(n)
        {
            string substring= s2.substr(i, s1.size());
            sort(substring.begin(), substring.end());
            //O(mlogm)
            if (s1==substring)
                return true;
        }
        return false;
    }
};
//n=length of s2
//m=length of s1
//TC O(nmlogm)
//SC O(m)
