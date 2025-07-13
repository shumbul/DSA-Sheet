class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap; //It stores the top K largest elements seen so far
    int K = 0;
public:
    KthLargest(int k, vector<int>& nums) { //O(nlogk)
        K = k; //the rank of the largest element we want to track.
        for (int num : nums) {
            min_heap.push(num);
        }
        while (!min_heap.empty() && min_heap.size() > k) {
            min_heap.pop(); //If the heap grows larger than K, we pop the smallest elements
        }
    }
    int add(int val) { //O(logk)
        min_heap.push(val);
        if (min_heap.size() > K)
        {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
//SC O(k)
