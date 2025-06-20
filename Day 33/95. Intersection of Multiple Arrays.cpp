class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> result(nums[0].begin(), nums[0].end()); //initialize with first array
        for (int i = 1; i < nums.size(); ++i) {
            set<int> current(nums[i].begin(), nums[i].end());
            set<int> temp;
            for (int num : result) {
                if (current.count(num)) {
                    temp.insert(num); //only insert common elements
                }
            }
            result = temp; //update result to intersection
        }
        return vector<int>(result.begin(), result.end()); //convert to vector
    }
};
