class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        map<int, int> freq;
        int ans=0, odd=0;
        for (int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        for (auto val:freq)
        {
            if (val.second%2==0)
            {
                ans=ans+val.second;
                //to divide no. of letters into halves
            }
            else
            {
                ans=ans+val.second-1;
                //choose only even part of odd frequencies to divide into halves
                odd=1;
                //1 odd frequency will be left which can be kept in middle, so we count only once
            }
        }
        return ans+odd;
    }
};
//TC O(N)
//SC O(N)
