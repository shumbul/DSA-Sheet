class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window; //stores indices of potential maximums in the current window. It maintains a monotonic decreasing order of values
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front(); // if front idx is out of window, i.e. before sliding window range, pop idx out of queue
            }
            while (!window.empty() && nums[i] >= nums[window.back()]) { //those elements can never be max again because nums[i] is more recent and bigger. This maintains a decreasing order of values from front to back of the deque
                window.pop_back();
            }
            window.push_back(i); //this index may become the max for upcoming windows
            if (i>=k-1)
                ans.push_back(nums[window.front()]); //max is always at the front of the deque
        }
        return ans;
    }
};
//TC O(N)
//SC O(N^2)
