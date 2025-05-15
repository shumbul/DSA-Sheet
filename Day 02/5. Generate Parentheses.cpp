class Solution 
{
    vector<string> ans;
    //declared globally
public:
    vector<string> generateParenthesis(int n) 
    {
        int openCount=0;
        string s;
        create(n,openCount,s);
        return ans;
    }
    void create(int n, int openCount, string s)
    //void so that there is nothing to return
    {
        if (openCount<(s.size()-openCount))
            return;
        if (openCount>n)
            return;
        if (s.size()==2*n)
        {
            ans.push_back(s);
        }
        create(n, openCount+1, s+'(');
        //recursion, same function is called with both possibilities
        create(n, openCount, s+')');
        //using if condition, wohi answer ans me push hoga jo chahiye
    }
};
//breaking conditions are used so that recursion stops at one point
//TC O(N)
//SC O(N
