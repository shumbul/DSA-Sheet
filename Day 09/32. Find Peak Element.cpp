class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size()==1)
            return 0;
        if (nums[0]>nums[1])
            return 0;
        if (nums[nums.size()-2]<nums[nums.size()-1])
            return nums.size()-1;
        int start=0, end=nums.size()-1;
        int ans=binarySearch(start, end, nums);
        return ans;
    }
    int binarySearch(int start, int end, vector<int>& nums)
    {
        if (start==end)
            return start;
        int ans_left=0, ans_right=0;
        int mid=start+(end-start)/2;
        if (nums[mid+1]<nums[mid] && nums[mid-1]<nums[mid])
        {
            return mid;
        } 
        // else
        //this condition is redundant when used with else case 
        if (nums[mid]>nums[mid+1]) //if right no is small, then check left no
        {
            ans_left=binarySearch(start, mid, nums); 
            return ans_left;
        } 
        else //if left no is small, then check right no
        {
            ans_right=binarySearch(mid+1, end, nums);
            return ans_right;
        }
    }
};
//TC O(logn)
//SC O(logn) because of recursion
