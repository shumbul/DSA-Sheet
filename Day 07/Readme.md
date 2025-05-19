## 🔍 Binary Search

---

### 📌 What is Binary Search?

Binary Search is a **divide and conquer** algorithm used to efficiently search for an element in a **sorted** array or range. It reduces the search space by half in every step.

---

### 🧠 When to Use

* You are working with a **sorted array** or **monotonic function**
* Need to **find an exact element, boundary, or condition** in O(log n)
* Problems like:

  * Search in Rotated Sorted Array
  * Minimum in Rotated Array
  * First/Last Occurrence
  * Peak Element
  * Finding a number that satisfies a condition (with function mapping)

---

### 🔸 Binary Search Types

| Type                     | Use Case Example                                                                                       |
| ------------------------ | ------------------------------------------------------------------------------------------------------ |
| Classic Binary Search    | Search for a target in a sorted array                                                                  |
| Lower/Upper Bound Search | Find first/last occurrence, boundaries                                                                 |
| Binary Search on Answer  | Find smallest/largest possible value meeting a condition (usually applied over a **range of answers**) |

---

### ✅ Example 1: Classic Binary Search

**Problem**: Search in a sorted array

```cpp
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1; // Not found
}
```

🧩 **Use-case**: Find the position of a student’s score in a sorted rank list.

---

### ✅ Example 2: Lower Bound (First Occurrence)

**Problem**: First occurrence of a number in sorted array

```cpp
int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
```

🧩 **Use-case**: Find earliest time where condition starts to be true.

---

### ✅ Example 3: Binary Search on Answer

**Problem**: Find minimum size subarray with sum ≥ `target`

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 1, right = nums.size(), ans = 0;

    auto isValid = [&](int len) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= len) sum -= nums[i - len];
            if (i >= len - 1 && sum >= target) return true;
        }
        return false;
    };

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isValid(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
```

🧩 **Use-case**: Find minimum time to achieve a goal under constraints.

---

### 📝 Summary

| Technique               | Use Case                                            | Time Complexity     |
| ----------------------- | --------------------------------------------------- | ------------------- |
| Classic Binary Search   | Exact match in sorted array                         | O(log n)            |
| Lower/Upper Bound       | First or last occurrence, floor/ceil                | O(log n)            |
| Binary Search on Answer | Search across answer space with validation function | O(log range × f(n)) |

---

💡 **Bonus Tips**:

* Always check for **sorted input or monotonicity**
* Watch out for **integer overflow** in `mid = (low + high) / 2`
* Prefer `mid = low + (high - low) / 2` for safe coding
* Binary Search is not just for arrays—it works great for **searching optimal values** too!

---
