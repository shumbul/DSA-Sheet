// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution 
{
public:
    int maximumCount(vector<int>& nums) 
    {
        int start = 0, end = nums.size() - 1;
        int neg = 0, pos = 0;
        // Count negative numbers
        while (start <= end) 
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < 0) 
            {
                neg = mid + 1; // all elements till mid are negative
                start = mid + 1;
            } 
            else 
            {
                end = mid - 1;
            }
        }
        // Count positive numbers
        start = 0, end = nums.size() - 1;
        while (start <= end) 
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= 0) 
            {
                start = mid + 1;
            } 
            else 
            {
                pos = nums.size() - mid; // all elements from mid to end are positive
                end = mid - 1;
            }
        }
        return max(neg, pos);
    }
};
//TC O(logn)
//SC O(1)

class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int pos=lower_bound(nums.begin(), nums.end(), 1)-nums.begin(); 
        //nums.begin() se iterators cancel ho jayenge aur relative position aa jayegi i.e. distance
        //if 1 is not present, it will give smallest positive no.
        int neg=upper_bound(nums.begin(), nums.end(), -1)-nums.begin();
        //if -1 is not present, it will give largest negative no.
        int pos_count=nums.size()-pos;
        return max(neg, pos_count);
    }
};
//TC O(logn)
//stl version of binary search
//SC O(1)

class Solution {
    int bin_search(vector<int> &nums, int target) {
        int start=0, end=nums.size()-1, ans=nums.size();

        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
                ans=mid; // lower bound
            }
        }
        return ans;
    }
public:
    int maximumCount(vector<int>& nums) {
        int minpositive = bin_search(nums, 1); // gives idx of first occurrence of 1 or greater
        int minzero = bin_search(nums, 0); // gives idx of first occurrence of 0 or greater
        
        int totalpositive = nums.size()-minpositive;
        int totalnegative = minzero; 
        return max(totalpositive, totalnegative);
        // TC: O(logn)
        // SC: O(1)
    }
};
