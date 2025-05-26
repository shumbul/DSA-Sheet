class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;
        if (nums.size()<3)
        {
            if (nums.size()==1)
                return nums;
            if (nums[0]==nums[1])
            {
                ans.push_back(nums[0]);
                return ans;
            }
            else
                return nums;
        }
        unordered_map<int, int> freq;
        int nby3=nums.size()/3;
        for (int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for (int i=0;i<nums.size();i++)
        {
            auto it=find(ans.begin(), ans.end(), nums[i]); //check if no.is already in ans
            if (freq[nums[i]]>nby3 && it==ans.end())
            {
                ans.push_back(nums[i]);
                //push if no. was not in ans
            }
        }
        return ans;
    }
};
//TC O(N)
//SC O(N)
