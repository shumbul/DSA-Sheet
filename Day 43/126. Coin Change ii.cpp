class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return helper(coins, amount, 0);
    }
    int helper(vector<int>& coins, int amount, int curridx) {
        // If amount is exactly 0, 1 valid way is found
        if (amount == 0)
            return 1;   
        // If no coins left or amount is negative, means invalid
        if (curridx >= coins.size() || amount < 0)
            return 0;
        // Option 1: take the coin (stay at same index)
        int take = helper(coins, amount - coins[curridx], curridx);
        // Option 2: don't take the coin (move to next index)
        int skip = helper(coins, amount, curridx + 1);
        return take + skip;
    }
};
//TC O(2^N)
//SC O(N)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Create a 2D DP table: dp[i][amt] = number of ways to make 'amt' using coins[i to end]
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        // Start recursion from index 0 with full amount
        return helper(coins, amount, 0, dp);
    }
    int helper(vector<int>& coins, int amount, int curridx, vector<vector<int>>& dp) {
        // Base Case 1: If amount becomes 0, we found 1 valid way
        if (amount == 0)
            return 1;
        // Base Case 2: If amount is negative or no coins left, this path is invalid
        if (curridx >= coins.size() || amount < 0)
            return 0;
        // If we already solved this subproblem, return cached result
        if (dp[curridx][amount] != -1)
            return dp[curridx][amount];
        // Option 1: Take the current coin (stay at same index since coins are unlimited)
        int take = helper(coins, amount - coins[curridx], curridx, dp);
        // Option 2: Skip the current coin (move to next index)
        int skip = helper(coins, amount, curridx + 1, dp);
        // Total ways = ways by taking + ways by skipping
        dp[curridx][amount] = take + skip;
        return dp[curridx][amount];
    }
};
//TC O(N)
//SC O(N*amount)
