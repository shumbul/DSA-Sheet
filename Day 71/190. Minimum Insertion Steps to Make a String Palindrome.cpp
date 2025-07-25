class Solution {
public:
    int minInsertions(string s) { 
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp); 
    }
    int helper(int start, int end, string& s, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (s[start] == s[end]) {
            dp[start][end] = helper(start + 1, end - 1, s, dp);
        } 
        else {
            dp[start][end] = 1 + min(helper(start + 1, end, s, dp), helper(start, end - 1, s, dp));
        }
        return dp[start][end];
    }
};
