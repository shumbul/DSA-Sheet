class Solution 
{
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        unordered_map<int, int> seen; //tracks frequency of each no.
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            seen[nums[i]]++;
        }
        for (int i=0;i<nums.size();i++)
        {
            if (seen[nums[i]]==1) //if no. appears once
            {
                if (seen[nums[i]+1]==0 && seen[nums[i]-1]==0) //if no neighbours present
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
//TC O(N)
//SC O(N)
