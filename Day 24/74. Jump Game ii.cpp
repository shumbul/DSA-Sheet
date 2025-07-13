//greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int farthest = 0;
        int end = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};

//recursion
class Solution 
{
    vector<int> dp;
public:
    int jump(vector<int>& nums)
    {
        dp.resize(nums.size(), -1);
        return helper(nums, 0); //start from idx 0
    }
    long long helper(vector<int>& nums, int idx)
    {
        if (idx>=nums.size()-1)
            return 0;
         if (dp[idx]!=-1)
            return dp[idx];
        long long temp=INT_MAX; //min no of jumps from this idx
        for (int jump=0;jump<nums[idx];jump++)
        {
            temp=min(temp, 1+helper(nums, jump+1+idx)); //try all possible jumps from 1 to nums[idx]
        }
        return dp[idx]=temp;
    }
};
//TC O(N*K)
//SC O(N)
