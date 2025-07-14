/*Since we only need the last two dp values at each step, we can:
Use 2 variables:
prev1 for dp[i-1]
prev2 for dp[i-2]
Compute curr (which is dp[i])
Then update:
prev2 = prev1
prev1 = curr*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        if (n == 1) 
            return nums[0];
        if (n == 2) 
            return max(nums[0], nums[1]);
        int ans1 = robLinear(nums, 0, n - 2);
        int ans2 = robLinear(nums, 1, n - 1);
        return max(ans1, ans2);
    }
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0; //best result 2 houses back
        int prev1 = 0; //best result 1 house back
        for (int i = start; i <= end; i++) {
        //at every house i:
        //rob it: add its money to the amount from i-2 (prev2)
        //skip it: keep the best amount up to i-1 (prev1)
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
