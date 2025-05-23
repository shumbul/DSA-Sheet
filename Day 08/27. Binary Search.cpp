class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int start=0, end=nums.size();
        while (start<end)
        {
            int mid=start+(end-start)/2;
            if (nums[mid]>target)
            {
                end=mid;
            }
            else if (nums[mid]<target)
            {
                start=mid+1;
            }
            else
                return mid;
        }
        return -1;
    }
};
//TC O(logn)
//SC O(1)
