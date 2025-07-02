# ✅ Dynamic Programming: From Recursion to Optimization

---

## 🔍 What Is Dynamic Programming?

Dynamic Programming (DP) is a technique used to solve problems that have:
- **Overlapping subproblems**
- **Optimal substructure**

We solve them using:
1. **Recursion** – the naive way (but exponential)
2. **Memoization** – recursion + cache (top-down DP)
3. **Tabulation** – iterative + array (bottom-up DP)

---

## 🧠 Learning Path: From Recursion to DP

Let’s take **Jump Game-style problems** to understand how we evolve from brute force to efficient DP.

---

### 🚀 Step 1: Recursion

We try all possible ways from current index to the end.

```cpp
bool canReachEnd(int i, vector<int>& nums) {
    if (i >= nums.size() - 1) return true;
    for (int jump = 1; jump <= nums[i]; jump++) {
        if (canReachEnd(i + jump, nums)) return true;
    }
    return false;
}
````

⛔ Time Complexity: **O(2ⁿ)** (TLE for large inputs)

---

### 🚀 Step 2: Memoization (Top-Down DP)

We avoid recomputing by storing answers in a `dp[]`.

```cpp
bool canReachEnd(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size() - 1) return true;
    if (dp[i] != -1) return dp[i];

    for (int jump = 1; jump <= nums[i]; jump++) {
        if (canReachEnd(i + jump, nums, dp)) return dp[i] = true;
    }

    return dp[i] = false;
}
```

✅ Time Complexity: **O(n²)** (improved by pruning)

---

### 🚀 Step 3: Tabulation (Bottom-Up DP)

We build from the end and check if it's reachable.

```cpp
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[n-1] = true;

    for (int i = n-2; i >= 0; i--) {
        for (int jump = 1; jump <= nums[i] && i + jump < n; jump++) {
            if (dp[i + jump]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}
```

⏳ Time Complexity: **O(n²)**
🧠 Space: O(n)

---

### 🚀 Step 4: Greedy (Optimized if possible)

Some DP problems (like Jump Game I) can be further optimized using **Greedy**:

```cpp
bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] >= goal) goal = i;
    }
    return goal == 0;
}
```

✅ Time: **O(n)**
✅ Space: **O(1)**

---

## 📚 Popular Problems to Learn DP Progression

| Problem         | Link                                                      | Learnings                          |
| --------------- | --------------------------------------------------------- | ---------------------------------- |
| Jump Game I     | [LeetCode](https://leetcode.com/problems/jump-game)       | DP to Greedy transition            |
| Jump Game II    | [LeetCode](https://leetcode.com/problems/jump-game-ii)    | Min steps → DP with min comparison |
| House Robber I  | [LeetCode](https://leetcode.com/problems/house-robber)    | Classic 1D DP                      |
| Climbing Stairs | [LeetCode](https://leetcode.com/problems/climbing-stairs) | Fibonacci-style DP                 |
| Frog Jump       | [GFG](https://www.geeksforgeeks.org/problems/geek-jump/1) | Minimum energy DP                  |

---

## 🧠 Final Takeaways

| Recursion          | Simple to write, but slow     |
| ------------------ | ----------------------------- |
| Memoization        | Speeds up recursion           |
| Tabulation         | Faster & iterative            |
| Space Optimization | Use two variables if possible |
| Greedy             | Sometimes replaces DP         |

---

## 🔗 External Playlists

* [NeetCode DP Playlist](https://www.youtube.com/playlist?list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf)
* [CodeHelp DP Sheet](https://www.naukri.com/code360/problems?tag=dynamic-programming)

---

### 🎯 TL;DR

Start with Recursion → Convert to Memoization → Build Tabulation → Look for Optimization (Greedy, Space Reduction).

This is the **path to mastering DP** 🚀
