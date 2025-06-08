class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        auto it=min_element(arr.begin(), arr.end())-arr.begin();
        if (arr[it]!=0)
            return false;
        return helper(start, arr);
    }
    bool helper(int place, vector<int>& nums)
    {
        if (place<0 || place>=nums.size() || nums[place]<0)
            return false;
        if (nums[place]==0)
            return true;
        bool optn1, optn2;
        if (nums[place]>0)
        {
            nums[place]*=-1; //indicates it is visited
            optn1=helper(place-nums[place], nums);
            optn2=helper(place+nums[place], nums);
        }
        return (optn1 | optn2);
    }
};
