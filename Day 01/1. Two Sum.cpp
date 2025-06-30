// Bruteforce - 
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> pairs;
        for (int i=0;i<nums.size();i++)
        { 
            int num1=nums[i];
            for (int j=i+1;j<nums.size();j++)
            {
                if (target-num1==nums[j])
                {
                    //1. push first num only if difference exists
                    //pairs.push_back(i);
                    //pairs.push_back(j);
                    //2. directly return pairs
                    return {i,j};
                }
            }
        }
        return {};
        //TC n^2
        //SC 1
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                // elements ahead
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
        // TC: O(n^2), SC: O(1)
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // key = elements previously seen, value = index
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])>0){
            // if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]]=i;
        }
        return {};
        // TC: O(nlogn), SC: O(n)
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // key = elements previously seen, value = index
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])>0){
            // if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]]=i;
        }
        return {};
        // TC: O(n), SC: O(n)
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i)
            arr.push_back({nums[i], i});
        //Sort the array by value
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                // Return the original indices
                return {arr[left].second, arr[right].second};
            } 
            else if (sum < target) 
            {
                left++;
            } 
            else 
            {
                right--;
            }
        }
        return {}; // Not found
    }
};
//TC O(N)
//SC O(1)
