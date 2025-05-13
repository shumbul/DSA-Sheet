// https://leetcode.com/problems/valid-anagram

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<int, int> freq;
        //key- letter, value- frequency
        for (int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
            //map is finding s[i]'s place to insert O(logn)
            //this increments the value and values are 0 by default
        }
        for (int i=0;i<t.size();i++)
        {
            freq[t[i]]--;
            //once ordered, O(1) is search time
            if (freq[t[i]]==0)
                freq.erase(t[i]);
        }
        if (freq.size()==0)
            return true;
        else
            return false;
    }
};
//TC O(nlogn)
//SC O(n) 
