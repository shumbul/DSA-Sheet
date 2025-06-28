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

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int idx=-1;
        int count1=0;
        for (int i=0;i<nums.size();i++)
        { //which no. is possible
            if (count==0)
            {
                idx=nums[i];
                count=1;
            }
            else if (idx==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        for (int i=0;i<nums.size();i++)
        { //confirm if that no. is possible
            if (idx==nums[i])
            {
                count1++;
            }
        }
        if (count1>nums.size()/2)
            return idx;
        return -1;
    }
};
//TC O(2N)
