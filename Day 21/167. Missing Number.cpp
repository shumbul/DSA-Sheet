class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i]; //xor vector
        }
        for (int i=0;i<=nums.size();i++)
        {
            ans=ans^i; //xor 0 to n
        }
        return ans; //remaining numbers will get cancelled
    }
};
