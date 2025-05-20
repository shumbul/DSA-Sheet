class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        string ans_odd="", ans_even="", odd="", even="";
        for (int i=0;i<s.size();i++)
        {
             odd=helper(i,i,s);
             //odd length
            if (ans_odd.size()<odd.size())
                ans_odd=odd;
            even=helper(i,i+1,s);
            //even length
            if (ans_even.size()<even.size())
                ans_even=even;
        }
        if (ans_odd.size()>ans_even.size())
            return ans_odd;
        else
            return ans_even;
    }
    string helper(int left, int right, string s)
    {
            while ((left>=0 && right<s.size()) && s[left]==s[right])
            //
            {
                left--;
                right++;
                //happens once extra and that is when while condition is false
            }
            left++;
            right--;
            //to reduce the one extra iteration that occured, this covers the condition that in case we go outside string, and we also want to come back to the boundary of palindrome
            return s.substr(left, right-left+1);
        
    }
};
