class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        reverse(s.begin(), s.end());
        //O(N) for reverse
        int count=0;
        for (int i=0;i<s.size();i++)
        //O(N) FOR FOR LOOP
        {
            if (count!=0)
            {
                if (s[i]==' ')
                {
                    return count;
                    break;
                }
            }
            if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
                count++;
        }
        return count;
    }
};
//TC O(N)
//SC O(1)
