class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int size=s.size();
        for (int i=0;i<size/2;i++)
        {
            swap(s[i], s[s.size()-i-1]);
        }
    }
};
//TC O(N)
//SC O(1)
