# 📝 Notes on `Stack` and `Queue` in C++

---

## 📦 Stack

A **Stack** is a **Last-In-First-Out (LIFO)** data structure.

### 📌 Basic Operations

| Operation | Description                 | Time Complexity |
| --------- | --------------------------- | --------------- |
| `push(x)` | Insert an element `x`       | O(1)            |
| `pop()`   | Remove top element          | O(1)            |
| `top()`   | Get the top element         | O(1)            |
| `empty()` | Check if stack is empty     | O(1)            |
| `size()`  | Number of elements in stack | O(1)            |

### ✅ Example (Using STL)

```cpp
#include <stack>
stack<int> s;

s.push(10);
s.push(20);
s.pop();           // removes 20
int top = s.top(); // 10
bool isEmpty = s.empty();
```

---

## 🚉 Queue

A **Queue** is a **First-In-First-Out (FIFO)** data structure.

### 📌 Basic Operations

| Operation | Description                    | Time Complexity |
| --------- | ------------------------------ | --------------- |
| `push(x)` | Enqueue: Insert an element `x` | O(1)            |
| `pop()`   | Dequeue: Remove front element  | O(1)            |
| `front()` | Get the front element          | O(1)            |
| `empty()` | Check if queue is empty        | O(1)            |
| `size()`  | Number of elements in queue    | O(1)            |

### ✅ Example (Using STL)

```cpp
#include <queue>
queue<int> q;

q.push(1);
q.push(2);
q.pop();             // removes 1
int front = q.front(); // 2
```

---

## 🔁 Deque (Double-ended Queue)

Allows insertion and deletion from both front and back.

```cpp
#include <deque>
deque<int> dq;

dq.push_front(1);
dq.push_back(2);
dq.pop_front();  // removes 1
dq.pop_back();   // removes 2
```

---

## 🧠 Conceptual Tips

* Use **stack** for **reversing**, **undo operations**, **DFS**, **valid parentheses**, **next greater element** problems.
* Use **queue** for **level order traversal**, **BFS**, **producer-consumer** problems.

---

## 💡 Practice Problems

| No. | Problem Name                   | Link                                                                    |
| --- | ------------------------------ | ----------------------------------------------------------------------- |
| 1   | Valid Parentheses              | [LeetCode](https://leetcode.com/problems/valid-parentheses/)            |
| 2   | Min Stack                      | [LeetCode](https://leetcode.com/problems/min-stack/)                    |
| 3   | Implement Queue using Stacks   | [LeetCode](https://leetcode.com/problems/implement-queue-using-stacks/) |
| 4   | Daily Temperatures             | [LeetCode](https://leetcode.com/problems/daily-temperatures/)           |
| 5   | Number of Recent Calls (Queue) | [LeetCode](https://leetcode.com/problems/number-of-recent-calls/)       |
| 6   | Sliding Window Maximum (Deque) | [LeetCode](https://leetcode.com/problems/sliding-window-maximum/)       |

---
