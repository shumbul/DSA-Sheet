class Solution 
{
public:
    bool areOccurrencesEqual(string s) 
    {
        map<int, int> freq;
        for (int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        auto expected=freq[s[0]];
        // for (int i=0;i<s.size();i++)
        // {
        //     if (freq[s[i]]!=expected)
        //     {
        //         return false;
        //     }
        // }
        for (auto val:freq)
        {
            if (val.second!=expected)
                return false;
        }
        return true;
    }
};
//TC O(N)
//SC O(N)
