class Solution {
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp.resize(46, -1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        int count=helper(n);
        return count;
    }
    int helper(int n)
    {
        if (dp[n]!=-1)
            return dp[n];
        int count1=0, count2=0;
            count1+=helper(n-1); 
            count2+=helper(n-2); 
        return dp[n]=count1+count2;
    }
};
