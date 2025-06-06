class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k==num.size()) //removing all digits
            return "0";
        stack<char> nums; //to keep track of the digits
        string ans="", res="";
        for (auto i:num)
        {
            while (!nums.empty() && k>0 && nums.top()>i)
            {
                nums.pop(); //we want smaller digits toward the left
                k--;
            }
                nums.push(i);
        }
        while (!nums.empty() && k>0) //all remaining digits are in non-decreasing order
        {
            nums.pop();
            k--;
        }
        while (!nums.empty())
        {
            ans+=nums.top();
            nums.pop();
        }
        reverse(ans.begin(), ans.end());
        for (int i=0;i<ans.size();i++)
        {
            if (res.empty() && ans[i]=='0')
                continue; //removing leading zeros
            else
                res+=ans[i];
        }
        if (res=="")
            return "0";
        return res;
    }
};
//TC O(N)
//SC O(N)
