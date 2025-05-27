class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            sum+=i;
        }
        for (int i=0;i<n;i++)
        {
            sum-=nums[i];
        }// no. not in nums will be left
        return sum;
    }
};
