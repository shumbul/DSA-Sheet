# ✅ Monotonic Stack – The Power Pattern

---

## 🧠 What Is a Monotonic Stack?

A **Monotonic Stack** is a stack that maintains elements in either **increasing** or **decreasing** order — and it's *incredibly powerful* for problems involving "next greater/smaller" relationships.

> Think of it as a “memory” of previous elements where you can eliminate the irrelevant ones quickly and keep only potential candidates.

---

## 🚀 Why Use It?

- Convert brute force `O(n²)` to efficient `O(n)`
- Works brilliantly when solving problems with:
  - **Next Greater / Smaller Element**
  - **Previous Greater / Smaller Element**
  - **Collisions / Pair Eliminations**
  - **Temperature / Stock / Heights-based logic**

---

## 🔁 Common Approach (Template)

This works for most "Next Greater" or "Stack Simulation" problems:

```cpp
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && <condition involving st.top() and arr[i]>) {
        // Process or update result for st.top()
        st.pop();
    }
    st.push(i or arr[i]);
}
````

🔹 Replace `<condition>` based on problem:

* `arr[i] > arr[st.top()]` → **Next Greater Element**
* `arr[i] < arr[st.top()]` → **Next Smaller Element**

🔹 Use `i` in stack if you need index-based results (like `res[i]`)

🔹 Every element is pushed and popped **at most once** → `O(n)` time

---

## 📌 Pattern 1: Next Greater Element

### 👇 Problem:

**Given an array, return the next greater element for every item (or -1 if not present).**

### ✅ Approach:

1. Traverse from **left → right**
2. Keep indices in a stack
3. **Pop** until current element is greater than the top
4. **Store the current value** as the answer for popped index

### 🧪 Sample Code:

```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> res(nums.size(), -1);

    for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}
```

---

## 📌 Pattern 2: Asteroid Collision (Stack Simulation)

### 👇 Problem:

**Each asteroid moves left or right. If two meet, the smaller explodes. Return the final state.**

### ✅ Approach:

1. Use a stack to simulate asteroid movement
2. Push positive (right) asteroids directly
3. For negative (left) asteroids, compare with top:

   * If collision: pop smaller, or both if equal
   * Otherwise: push it

### 🧪 Sample Code:

```cpp
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int ast : asteroids) {
        bool alive = true;
        while (alive && ast < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -ast) st.pop();       // right side is weaker
            else if (st.top() == -ast) {
                st.pop(); alive = false;          // both explode
            } else alive = false;                 // left side destroyed
        }
        if (alive) st.push(ast);
    }

    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        res[i] = st.top(); st.pop();
    }
    return res;
}
```

---

## 🧪 Practice Problems

| Problem                           | Link                                                                     |
| --------------------------------- | ------------------------------------------------------------------------ |
| ✅ Next Greater Element I          | [LeetCode](https://leetcode.com/problems/next-greater-element-i)         |
| ✅ Asteroid Collision              | [LeetCode](https://leetcode.com/problems/asteroid-collision)             |
| 🔥 Daily Temperatures             | [LeetCode](https://leetcode.com/problems/daily-temperatures)             |
| 🔥 Sum of Subarray Minimums       | [LeetCode](https://leetcode.com/problems/sum-of-subarray-minimums)       |
| 🔥 Largest Rectangle in Histogram | [LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram) |

---

## 🧠 Final Tips

* **Always store indices** if you need to refer to positions
* **Pop until the stack becomes valid** again (i.e., maintains the monotonic property)
* Works beautifully with **arrays**, **strings**, or even **custom structs**
* Visualize the stack at each step for deeper clarity in interviews

---

### 🎯 TL;DR

Monotonic Stack helps you **reduce comparisons and remember only the useful stuff**.
If you ever hear "Next Greater", think *stack*, think *smart*. 
