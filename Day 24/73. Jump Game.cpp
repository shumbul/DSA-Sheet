class Solution {
    bool ans=false;
    vector<int> dp;
public:
    bool canJump(vector<int>& nums) 
    {
        dp.resize(nums.size(), -1);
        helper(nums, 0); //we start at idx 0
        return ans;
    }
    bool helper(vector<int>& nums, int idx)
    {
        if (idx>=nums.size()-1) //reached or exceeded last idx
        {
            ans= true;
            return ans;
        }
        if (nums[idx]==0) //no more jumps available
            return false;
        if (dp[idx]!=-1)
            return dp[idx]; //already computed result
        for (int jump=0;jump<nums[idx];jump++)
        {
            dp[idx]=helper(nums, jump+1+idx); //try all jumps from 1 to nums[idx]
            if (dp[idx]==true)
                return true;
        }
        return dp[idx];
    }
};
//TC O(N) 
//SC O(N)
