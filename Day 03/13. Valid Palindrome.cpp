class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        int i=0,j=s.size()-1;
        while (i<j)
        {
             if (!isalnum(s[i]))
                i++;
            //move pointer right
            else if (!isalnum(s[j]))
                j--;
            //move pointer left
            else if (tolower(s[i])==tolower(s[j]))
            {
                i++, j--;
                //move both pointers together
            }
            else
                return false;
        }
        return true;
    }
};
//TC O(N)
//SC O(1)
