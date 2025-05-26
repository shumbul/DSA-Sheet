class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        for (int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for (int i=0;i<nums.size();i++)
        {
            if (freq[nums[i]]>nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};
//TC O(n)
//SC O(n)

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

//TC O(nlogn)
//SC O(1)
