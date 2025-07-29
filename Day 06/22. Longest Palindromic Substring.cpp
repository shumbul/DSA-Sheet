//recursion
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

class Solution {
public:
    string longestPalindrome(string s) {
        set<string> substr;
        string ans = "";
        for (int i = 0; i <= s.size() - 1; i++) {
            string st = "";
            st += s[i];
            substr.insert(st);
            for (int j = i + 1; j < s.size(); j++) {
                st += s[j];
                substr.insert(st);
            }
        }
        for (auto str : substr) {
            bool flag = true;
            int left = 0;
            int right = str.size() - 1;
            while (left <= right) {
                if (str[left] != str[right]) {
                    flag = false;
                    break;
                } 
                else {
                    left++;
                    right--;
                }
            }
            if (flag) {
                if (ans.size() < str.size())
                    ans = str;
            }
        }
        return ans;
    }
};
/*Generating all substrings is O(n²)
Inserting into a set is O(log n)
Checking each substring is O(n)
TC: O(n³ log n)*/

