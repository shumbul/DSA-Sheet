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
