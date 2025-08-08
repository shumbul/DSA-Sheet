class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) 
            return 1.0; // Large n approximation
        int units = (n + 24) / 25; // Scale down to multiples of 25
        vector<vector<double>> dp(units + 1, vector<double>(units + 1, -1.0));
        return dfs(units, units, dp);
    }
    double dfs(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0) 
            return 0.5;
        if (a <= 0) 
            return 1.0;
        if (b <= 0) 
            return 0.0;
        if (dp[a][b] >= 0) 
            return dp[a][b];
        double prob = 0.25 * (dfs(a - 4, b, dp) + dfs(a - 3, b - 1, dp) + dfs(a - 2, b - 2, dp) + dfs(a - 1, b - 3, dp));
        return dp[a][b] = prob;
    }
};
