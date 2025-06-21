class Solution {
public:
    int rob(vector<int>& nums) {
        return helper(nums, 0);
    }
    int helper(vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;
        //rob current house
        int rob = nums[i] + helper(nums, i + 2);
        //skip current house
        int skip = helper(nums, i + 1);
        return max(rob, skip);
    }
};
//TC O(2^N)
//SC O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        if (n == 1) 
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];                                
        dp[1] = max(nums[0], nums[1]);                
        for (int i = 2; i < n; i++) 
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]); //either rob this house and add dp[i-2], or skip it and take dp[i-1]
        }
        return dp[n - 1];   //max profit till last house
    }
};
//TC O(N)
//SC O(N)
