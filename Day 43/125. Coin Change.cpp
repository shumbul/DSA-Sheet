//greedy-> giving wrong answer
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend()); // Sort in descending order
        int count = 0;
        for (int coin : coins) {
            if (amount == 0) 
                break;
            if (coin <= amount) {
                int take = amount / coin; // take as many of this coin as possible
                count += take;
                amount -= take * coin;
            }
        }
        if (amount==0)
            return count;
        return -1; // if we couldn't form amount, return -1
    }
};

//recursion
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount, 0);
    }
    int helper(vector<int>& coins, int amount, int curridx)
    {
        if (curridx>=coins.size())
            return 0;
        if (amount<0)
            return -1;
        
        int ans=0;
        if (coins[curridx]>amount)
        {
            int dontTake=helper(coins, amount, curridx+1);
            ans=dontTake;
        }
        else
        {
            int takeCoin=1+helper(coins, amount-coins[curridx], curridx);
            int dontTake=helper(coins, amount, curridx+1);
            ans=min(takeCoin, dontTake);
        }
        return ans;
    }
};

//dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); //row is current coin in coins, col is remaining amount to make, dp[i][j] stores the minimum number of coins needed to make amount j using coins from index i to the end of the coins array.
        int res = helper(coins, amount, 0, dp);
        if (res>=1e9)
            return -1;
        return res;
    }
    int helper(vector<int>& coins, int amount, int curridx, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (curridx >= coins.size())
            return 1e9;  // impossible case
        if (dp[curridx][amount] != -1)
            return dp[curridx][amount];
        int take = 1e9, skip = 1e9;
        if (coins[curridx] <= amount)
            take = 1 + helper(coins, amount - coins[curridx], curridx, dp);
        skip = helper(coins, amount, curridx + 1, dp);
        return dp[curridx][amount] = min(take, skip);
    }
};
