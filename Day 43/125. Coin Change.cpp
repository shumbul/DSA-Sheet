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
