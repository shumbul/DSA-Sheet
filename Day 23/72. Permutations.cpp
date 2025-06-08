class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums); //first permutation
        while (next_permutation(nums.begin(), nums.end()))
        {
                ans.push_back(nums);
        }
        return ans;
    }
};
