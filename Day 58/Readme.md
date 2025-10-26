# 🔺 Day 58: Heap & Priority Queue Mastery

## 📚 Table of Contents
1. [Heap Fundamentals](#heap-fundamentals)
2. [Priority Queue Operations](#priority-queue-operations)
3. [Core Patterns](#core-patterns)
4. [Advanced Techniques](#advanced-techniques)
5. [Problem Categories](#problem-categories)
6. [Interview Strategy](#interview-strategy)

---

## 🏗️ Heap Fundamentals

A **heap** is a complete binary tree that satisfies the heap property. It's the underlying data structure for priority queues and provides efficient insertion, deletion, and finding of extreme values.

### **Heap Properties:**
- **Complete Binary Tree**: All levels filled except possibly the last, which is filled left-to-right
- **Heap Property**: 
  - **Max Heap**: Parent ≥ children
  - **Min Heap**: Parent ≤ children

### **Array Representation:**
```cpp
// For 0-indexed array:
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// For 1-indexed array (sometimes easier):
int parent(int i) { return i / 2; }
int leftChild(int i) { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }
```

### **Complete Min-Heap Implementation:**
```cpp
class MinHeap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] >= heap[parentIndex]) break;
            
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }
    
    void heapifyDown(int index) {
        int size = heap.size();
        
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest == index) break;
            
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return minValue;
    }
    
    int getMin() const {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }
    
    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }
    
    // Build heap from array in O(n) time
    void buildHeap(vector<int>& arr) {
        heap = arr;
        
        // Start from last non-leaf node and heapify down
        for (int i = (heap.size() - 2) / 2; i >= 0; i--) {
            heapifyDown(i);
        }
    }
};
```

---

## ⚙️ Priority Queue Operations

C++ STL provides `priority_queue` which is a max-heap by default.

### **Basic Usage:**
```cpp
#include <queue>

class PriorityQueueExamples {
public:
    void basicOperations() {
        // Max heap (default)
        priority_queue<int> maxHeap;
        maxHeap.push(3);
        maxHeap.push(1);
        maxHeap.push(4);
        
        cout << maxHeap.top() << endl;  // Output: 4
        maxHeap.pop();
        cout << maxHeap.top() << endl;  // Output: 3
        
        // Min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(3);
        minHeap.push(1);
        minHeap.push(4);
        
        cout << minHeap.top() << endl;  // Output: 1
        
        // Custom comparator
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;  // Min heap based on second element
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> customHeap(cmp);
        customHeap.push({1, 10});
        customHeap.push({2, 5});
        customHeap.push({3, 15});
        
        cout << customHeap.top().first << endl;  // Output: 2 (smallest second value)
    }
};
```

### **Custom Objects in Priority Queue:**
```cpp
struct Task {
    int id;
    int priority;
    string description;
    
    Task(int i, int p, string d) : id(i), priority(p), description(d) {}
};

// Method 1: Comparator function
struct TaskComparator {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority;  // Max heap based on priority
    }
};

// Method 2: Overload operator<
bool operator<(const Task& a, const Task& b) {
    return a.priority < b.priority;  // For max heap
}

class TaskScheduler {
public:
    void example() {
        priority_queue<Task, vector<Task>, TaskComparator> taskQueue;
        
        taskQueue.push(Task(1, 5, "Low priority"));
        taskQueue.push(Task(2, 10, "High priority"));
        taskQueue.push(Task(3, 7, "Medium priority"));
        
        while (!taskQueue.empty()) {
            Task current = taskQueue.top();
            taskQueue.pop();
            cout << current.description << " (Priority: " << current.priority << ")" << endl;
        }
    }
};
```

---

## 🎯 Core Patterns

### **Pattern 1: K Largest/Smallest Elements**

#### **Kth Largest Element**
```cpp
class KthLargest {
public:
    // Method 1: Using min heap of size k
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
    
    // Method 2: Using quickselect (average O(n))
    int findKthLargestQuickSelect(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
private:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int pivotIndex = partition(nums, left, right);
        int rank = right - pivotIndex + 1;  // Rank from the right (largest)
        
        if (rank == k) {
            return nums[pivotIndex];
        } else if (rank > k) {
            return quickSelect(nums, pivotIndex + 1, right, k);
        } else {
            return quickSelect(nums, left, pivotIndex - 1, k - rank);
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[i], nums[right]);
        return i;
    }
};
```

#### **Top K Frequent Elements**
```cpp
class TopKFrequent {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Min heap to maintain k elements with highest frequency
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;  // Min heap based on frequency
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto& p : freq) {
            minHeap.push({p.first, p.second});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return result;
    }
    
    // Alternative: Bucket sort approach O(n)
    vector<int> topKFrequentBucket(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        
        // Put numbers in buckets based on their frequency
        for (auto& p : freq) {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> result;
        
        // Collect from highest frequency buckets
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};
```

### **Pattern 2: Merge K Sorted Arrays/Lists**
```cpp
class MergeKSorted {
public:
    // Merge k sorted arrays
    vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);  // Min heap based on value
        };
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> minHeap(cmp);
        
        // Initialize heap with first element from each array
        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays[i].empty()) {
                minHeap.push({arrays[i][0], i, 0});  // {value, array_index, element_index}
            }
        }
        
        vector<int> result;
        
        while (!minHeap.empty()) {
            auto [value, arrayIdx, elemIdx] = minHeap.top();
            minHeap.pop();
            
            result.push_back(value);
            
            // Add next element from the same array
            if (elemIdx + 1 < arrays[arrayIdx].size()) {
                minHeap.push({arrays[arrayIdx][elemIdx + 1], arrayIdx, elemIdx + 1});
            }
        }
        
        return result;
    }
    
    // Merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min heap
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Add all non-null heads to heap
        for (ListNode* head : lists) {
            if (head) {
                minHeap.push(head);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy->next;
    }
};
```

### **Pattern 3: Running Median/Statistics**
```cpp
class MedianFinder {
private:
    priority_queue<int> maxHeap;  // Left half (smaller elements)
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Right half (larger elements)
    
public:
    void addNum(int num) {
        // Add to appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance heaps (maxHeap can have at most 1 more element than minHeap)
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

// Sliding window median
class SlidingWindowMedian {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> result;
        
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            
            if (window.size() > k) {
                window.erase(window.find(nums[i - k]));
            }
            
            if (window.size() == k) {
                auto it = window.begin();
                advance(it, k / 2);
                
                if (k % 2 == 1) {
                    result.push_back(*it);
                } else {
                    auto prev_it = prev(it);
                    result.push_back(((long long)*prev_it + *it) / 2.0);
                }
            }
        }
        
        return result;
    }
};
```

---

## 🚀 Advanced Techniques

### **1. Custom Heap with Updates**
```cpp
class UpdatableHeap {
private:
    vector<int> heap;
    unordered_map<int, int> valueToIndex;  // value -> index mapping
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent]) break;
            
            swapElements(index, parent);
            index = parent;
        }
    }
    
    void heapifyDown(int index) {
        int size = heap.size();
        
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest == index) break;
            
            swapElements(index, smallest);
            index = smallest;
        }
    }
    
    void swapElements(int i, int j) {
        valueToIndex[heap[i]] = j;
        valueToIndex[heap[j]] = i;
        swap(heap[i], heap[j]);
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        valueToIndex[value] = heap.size() - 1;
        heapifyUp(heap.size() - 1);
    }
    
    void updateValue(int oldValue, int newValue) {
        if (valueToIndex.find(oldValue) == valueToIndex.end()) return;
        
        int index = valueToIndex[oldValue];
        valueToIndex.erase(oldValue);
        
        heap[index] = newValue;
        valueToIndex[newValue] = index;
        
        // Heapify in appropriate direction
        if (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
    }
    
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        
        int minValue = heap[0];
        valueToIndex.erase(minValue);
        
        if (heap.size() == 1) {
            heap.pop_back();
            return minValue;
        }
        
        heap[0] = heap.back();
        valueToIndex[heap[0]] = 0;
        heap.pop_back();
        
        heapifyDown(0);
        return minValue;
    }
};
```

### **2. Lazy Deletion in Heap**
```cpp
class LazyDeletionHeap {
private:
    priority_queue<int> heap;
    unordered_set<int> deleted;
    
    void cleanTop() {
        while (!heap.empty() && deleted.count(heap.top())) {
            heap.pop();
        }
    }
    
public:
    void insert(int value) {
        heap.push(value);
        deleted.erase(value);  // Remove from deleted set if present
    }
    
    void remove(int value) {
        deleted.insert(value);  // Mark as deleted
    }
    
    int top() {
        cleanTop();
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap.top();
    }
    
    void pop() {
        cleanTop();
        if (!heap.empty()) {
            heap.pop();
        }
    }
    
    bool empty() {
        cleanTop();
        return heap.empty();
    }
};
```

---

## 📊 Problem Categories

### **Category 1: Selection Problems**
- Kth largest/smallest element
- Top K frequent elements
- Kth largest in stream

### **Category 2: Merge Problems**
- Merge K sorted lists/arrays
- Smallest range covering elements from K lists

### **Category 3: Median/Statistics**
- Find median from data stream
- Sliding window median
- Running percentiles

### **Category 4: Scheduling/Simulation**
- Task scheduling with priorities
- CPU scheduling algorithms
- Event simulation

---

## 🎯 Interview Strategy

### **Problem Recognition:**
Look for these keywords:
- "Kth largest/smallest"
- "Top K"
- "Merge K sorted"
- "Median" or "running statistics"
- "Priority" or "scheduling"

### **Heap vs Other Data Structures:**

| Problem | Best Approach | Why |
|---------|---------------|-----|
| **Kth Largest** | Min heap (size k) | O(n log k) vs O(n log n) sort |
| **Top K Frequent** | Min heap or bucket sort | Efficient for small k |
| **Merge K Sorted** | Min heap | Better than merging pairs |
| **Running Median** | Two heaps | O(log n) insertion, O(1) median |
| **Range Queries** | Segment tree | Heap not suitable |

### **Common Pitfalls:**
1. **Wrong heap type**: Use min heap for K largest elements
2. **Size management**: Keep heap size exactly k for efficiency
3. **Custom comparators**: Be careful with comparison logic
4. **Memory management**: Clean up properly for repeated operations

### **Time Complexity Cheat Sheet:**
- **Insertion**: O(log n)
- **Deletion**: O(log n)
- **Find min/max**: O(1)
- **Build heap**: O(n) from array
- **Heap sort**: O(n log n)

---

## 🏆 Advanced Applications

### **1. Dijkstra's Algorithm Implementation**
```cpp
class DijkstraWithHeap {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;  // Skip outdated entries
            
            for (auto [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};
```

### **2. A* Search Algorithm**
```cpp
class AStarSearch {
public:
    int astar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
        int m = grid.size(), n = grid[0].size();
        
        auto heuristic = [&](int x, int y) {
            return abs(x - goal.first) + abs(y - goal.second);  // Manhattan distance
        };
        
        priority_queue<tuple<int, int, int, int>, 
                      vector<tuple<int, int, int, int>>, 
                      greater<tuple<int, int, int, int>>> pq;
        
        set<pair<int, int>> visited;
        
        pq.push({heuristic(start.first, start.second), 0, start.first, start.second});
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [f, g, x, y] = pq.top();
            pq.pop();
            
            if (x == goal.first && y == goal.second) {
                return g;
            }
            
            if (visited.count({x, y})) continue;
            visited.insert({x, y});
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] == 0 && !visited.count({nx, ny})) {
                    
                    int newG = g + 1;
                    int newF = newG + heuristic(nx, ny);
                    pq.push({newF, newG, nx, ny});
                }
            }
        }
        
        return -1;  // No path found
    }
};
```

---

## 🎮 Practice Progression

### **Level 1: Fundamentals**
1. Kth Largest Element in Array
2. Last Stone Weight
3. Top K Frequent Elements

### **Level 2: Intermediate**
4. Find Median from Data Stream
5. Merge k Sorted Lists
6. Kth Largest Element in Stream

### **Level 3: Advanced**
7. Sliding Window Median
8. Smallest Range Covering Elements from K Lists
9. Minimum Cost to Hire K Workers

---

*Master heaps and priority queues to efficiently solve selection, merging, and streaming problems! 🔺*