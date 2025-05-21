## 🍌 Binary Search for Interviews – *Koko Eating Bananas Pattern*

---

### 📌 What is Binary Search on Answer?

This is a pattern where you don't binary search in an array, but over a **range of possible answers** — typically when:

* You're asked to **minimize** or **maximize** a value
* There's a function to check whether a candidate answer is **valid or not**
* The validity of the answer is **monotonic** (if x is valid, all values > x are also valid or invalid)

---

### 🧠 Common Phrases in These Problems

* “Return the **minimum** X such that...”
* “What is the **smallest/largest** possible value...”
* “Given a time/resource limit, can we...?”

---

### ✅ Example: Koko Eating Bananas 🍌

> [LeetCode #875](https://leetcode.com/problems/koko-eating-bananas/)

**Problem Statement**:
Koko loves bananas and eats `k` bananas per hour. Each pile contains some bananas. Find the minimum `k` such that she can finish all bananas in `h` hours.

---

### 🔍 Binary Search Strategy

* **Search space**: `k` (bananas/hour) in range \[1, max(piles)]
* **Validation function**: Check if she can eat all bananas within `h` hours at current speed `k`

---

### 🧠 Key Insight

The more bananas she eats per hour, the **fewer hours** she takes.
This is a **monotonic** function → use binary search!

---

### ✅ Code

```cpp
bool canEatAll(vector<int>& piles, int h, int k) {
    int time = 0;
    for (int pile : piles) {
        time += (pile + k - 1) / k;  // Ceiling division
    }
    return time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canEatAll(piles, h, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}
```

---

### 🧩 Similar Problems

| Problem Name                              | Link                                                                              |
| ----------------------------------------- | --------------------------------------------------------------------------------- |
| Koko Eating Bananas                       | [#875](https://leetcode.com/problems/koko-eating-bananas/)                        |
| Minimum Number of Days to Make m Bouquets | [#1482](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) |
| Capacity To Ship Packages Within D Days   | [#1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)   |
| Split Array Largest Sum                   | [#410](https://leetcode.com/problems/split-array-largest-sum/)                    |

---

### 📝 Summary Table

| Component         | Description                                                     |
| ----------------- | --------------------------------------------------------------- |
| Search Space      | Range of possible answers (e.g., 1 to max pile size)            |
| Validity Function | Can the current candidate answer satisfy the condition?         |
| Goal              | Minimize or maximize the smallest/largest possible valid answer |
| Time Complexity   | `O(log(range) * N)`                                             |

---

💡 **Pro Tip**: Always identify the **range of answers**, and build a **validation function** for the current `mid`. If the function is monotonic (true → false or vice versa), Binary Search on Answer is the way to go!
