class Solution {
    vector<vector<int>> dp; //dp[idx][M] stores result starting from index 'idx' and M value
public:
    int stoneGameII(vector<int>& piles) 
    { 
        int n = piles.size();
        dp.resize(n, vector<int>(n + 1, -1));  //only need dp[n][n+1]
        return helper(piles, 0, 1); //start from pile 0, initial M=1
    }
    //max stones the current player can collect
    int helper(vector<int>& piles, int idx, int M) {
        int n = piles.size();
        if (idx >= n)
            return 0;
        if (dp[idx][M] != -1)
            return dp[idx][M];
        int maxStones = 0; //track max stones current player can collect
        int currSum = 0; //track running sum of stones picked in this move
        for (int x = 1; x <= 2 * M && idx + x <= n; ++x) {
            currSum += piles[idx + x - 1]; //add stones of xth pile to current sum
            int remaining = sum(piles, idx + x); // Stones left for opponent
            int opponent = helper(piles, idx + x, max(M, x));  //opponent plays optimally
            int myTotal = currSum + (remaining - opponent);  //my current+future stones
            maxStones = max(maxStones, myTotal);
        }
        return dp[idx][M] = maxStones;
    }
    int sum(vector<int>& piles, int idx) {
        return accumulate(piles.begin() + idx, piles.end(), 0);
    }
};
//TC O(N^3)
//SC O(N^2)

