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

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int count1 = 0, count2 = 0; //counters for the two possible majority candidates
        int candidate1 = 0, candidate2 = 1; //initial candidates (set to different values to avoid collision)
        //find up to two candidates 
        for (int num : nums)
        {
            if (num == candidate1) 
            {
                count1++;  // num matches first candidate
            } 
            else if (num == candidate2) 
            {
                count2++;  // num matches second candidate
            } 
            else if (count1 == 0) 
            {
                candidate1 = num; // no current first candidate, assign num
                count1 = 1;
            } 
            else if (count2 == 0) 
            {
                candidate2 = num; // no current second candidate, assign num
                count2 = 1;
            } 
            else 
            {
                count1--; // decrement both counts when no match
                count2--;
            }
        }
        //verify actual frequencies of the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) 
        {
            if (num == candidate1) 
                count1++;
            else if (num == candidate2) 
                count2++;
        }
        //add candidates to result if their count > n/3
        vector<int> result;
        if (count1 > n / 3) 
            result.push_back(candidate1);
        if (count2 > n / 3) 
            result.push_back(candidate2);
        return result;
    }
};
