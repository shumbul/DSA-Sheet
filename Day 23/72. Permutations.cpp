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

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dip = -1; //stores the rightmost index where the ascending order breaks.
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dip = i;
                break;
            } //This tells us the position where the permutation can still be incremented.
        }
        if (dip == -1) { //the permutation is the last one
            sort(nums.begin(), nums.end()); //first permutation
            return;
        }
        for (int i = n - 1; i > dip; i--) 
        { //Find the smallest number greater than nums[dip] to the right of dip.
            if (nums[dip] < nums[i]) {
                swap(nums[dip], nums[i]); //Swap it to move to the next higher permutation.
                break;
            }
        }
        reverse(nums.begin() + dip + 1, nums.end()); //Reverse the right part after dip to make it the smallest possible suffix
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // start from smallest permutation
        do {
            result.push_back(nums);     // store current permutation
            nextPermutation(nums);      // move to next
        } while (!is_sorted(nums.begin(), nums.end())); //Continue until we come back to the sorted order, which means we've cycled through all permutations.
        return result;
    }
};
//TC: O(n! × n)  → because we're generating n! permutations, each requiring O(n) work
//SC O(n!*n)
