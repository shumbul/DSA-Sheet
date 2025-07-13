class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;  // Count frequency
        }
        // Min-heap to keep top k elements by frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& [num, freq] : count) {
            minHeap.push({freq, num});  // Push (frequency, number)
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove least frequent
            }
        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
//TC: O(nlogk)
//SC: O(n)
