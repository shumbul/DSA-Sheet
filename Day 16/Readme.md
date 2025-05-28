# Stack, Queue & Monotonic Structures

---

## 🧱 Stack

A **Stack** is a linear data structure following **LIFO** (Last In, First Out).

### 🔧 Common Operations

| Operation          | Time Complexity |
| ------------------ | --------------- |
| `push()`           | O(1)            |
| `pop()`            | O(1)            |
| `top()` / `peek()` | O(1)            |
| `empty()`          | O(1)            |

### ✅ Use Cases

* Reversing data
* Validating parentheses
* Inorder/Preorder tree traversal
* Undo operations
* Backtracking

### 📌 Sample Code (C++)

```cpp
stack<int> st;
st.push(5);
st.pop();
int topElement = st.top();
bool isEmpty = st.empty();
```

---

## 📮 Queue

A **Queue** follows **FIFO** (First In, First Out).

### 🔧 Common Operations

| Operation | Time Complexity |
| --------- | --------------- |
| `push()`  | O(1)            |
| `pop()`   | O(1)            |
| `front()` | O(1)            |
| `empty()` | O(1)            |

### ✅ Use Cases

* Scheduling processes
* BFS traversal
* Cache implementation
* Task queues

### 📌 Sample Code (C++)

```cpp
queue<int> q;
q.push(10);
q.pop();
int front = q.front();
bool isEmpty = q.empty();
```

---

## 🔁 Enqueue and Dequeue (Queue Basics)

* **Enqueue**: Add element to the back of the queue.
* **Dequeue**: Remove element from the front of the queue.

### 📌 Example

```cpp
queue<int> q;
q.push(1); // enqueue
q.pop();   // dequeue
```

---

## 🧮 Monotonic Stack

A **Monotonic Stack** is a stack that maintains elements in **sorted order (increasing or decreasing)**.

### 🔧 Common Variants

* **Monotonic Increasing Stack** (for Next Greater Element)
* **Monotonic Decreasing Stack** (for Histogram problems)

### ✅ Use Cases

* Stock Span problems
* Daily Temperatures
* Largest Rectangle in Histogram

### 📌 Sample Code (Next Greater Element)

```cpp
vector<int> nextGreater(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

---

## 🧮 Monotonic Queue

A **Monotonic Queue** maintains a deque such that elements are always increasing or decreasing.

### ✅ Use Cases

* Sliding Window Maximum/Minimum
* Optimization in Greedy + Binary Search problems

### 📌 Sample Code (Sliding Window Max)

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove out-of-window elements
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
```

---

## ✅ **Practice Problems**

### 📦 Stack

| Problem                                  | Difficulty | Link                                                                         |
| ---------------------------------------- | ---------- | ---------------------------------------------------------------------------- |
| Valid Parentheses                        | Easy       | [🔗](https://leetcode.com/problems/valid-parentheses)                        |
| Min Stack                                | Medium     | [🔗](https://leetcode.com/problems/min-stack)                                |
| Evaluate Reverse Polish Notation         | Medium     | [🔗](https://leetcode.com/problems/evaluate-reverse-polish-notation)         |
| Asteroid Collision                       | Medium     | [🔗](https://leetcode.com/problems/asteroid-collision)                       |
| Remove All Adjacent Duplicates In String | Easy       | [🔗](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string) |

---

### 📮 Queue

| Problem                      | Difficulty | Link                                                             |
| ---------------------------- | ---------- | ---------------------------------------------------------------- |
| Implement Queue using Stacks | Easy       | [🔗](https://leetcode.com/problems/implement-queue-using-stacks) |
| Number of Recent Calls       | Easy       | [🔗](https://leetcode.com/problems/number-of-recent-calls)       |
| Dota2 Senate                 | Medium     | [🔗](https://leetcode.com/problems/dota2-senate)                 |

---

### 🔁 Enqueue / Dequeue

| Problem                        | Difficulty | Link                                                               |
| ------------------------------ | ---------- | ------------------------------------------------------------------ |
| Design Circular Queue          | Medium     | [🔗](https://leetcode.com/problems/design-circular-queue)          |
| Rotting Oranges (BFS)          | Medium     | [🔗](https://leetcode.com/problems/rotting-oranges)                |
| Shortest Path in Binary Matrix | Medium     | [🔗](https://leetcode.com/problems/shortest-path-in-binary-matrix) |

---

### 📊 Monotonic Stack

| Problem                        | Difficulty | Link                                                               |
| ------------------------------ | ---------- | ------------------------------------------------------------------ |
| Next Greater Element I         | Easy       | [🔗](https://leetcode.com/problems/next-greater-element-i)         |
| Daily Temperatures             | Medium     | [🔗](https://leetcode.com/problems/daily-temperatures)             |
| Largest Rectangle in Histogram | Hard       | [🔗](https://leetcode.com/problems/largest-rectangle-in-histogram) |
| Sum of Subarray Minimums       | Medium     | [🔗](https://leetcode.com/problems/sum-of-subarray-minimums)       |

---

### 📈 Monotonic Queue

| Problem                     | Difficulty | Link                                                            |
| --------------------------- | ---------- | --------------------------------------------------------------- |
| Sliding Window Maximum      | Hard       | [🔗](https://leetcode.com/problems/sliding-window-maximum)      |
| Constrained Subsequence Sum | Hard       | [🔗](https://leetcode.com/problems/constrained-subsequence-sum) |
| Jump Game VI                | Medium     | [🔗](https://leetcode.com/problems/jump-game-vi)                |

---
