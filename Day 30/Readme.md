# 🎮 Game Theory with Dynamic Programming

---

## 🧠 What Is Game Theory in DSA?

Game theory problems often involve:
- **Two players** taking turns
- **Perfect play** from both sides
- Determining **who will win** or what the **optimal score** is

🧩 Many of these problems can be solved using **DP + Min/Max strategy**.

---

## 📌 Key Concepts

| Concept             | Meaning                                                                 |
|---------------------|-------------------------------------------------------------------------|
| Optimal Strategy     | Both players make the best moves at every step                         |
| State Definition     | Usually `dp[i][j]` means max score a player can collect from i to j     |
| Turn-Based Decision  | If it's your turn, you maximize the result; if opponent's, minimize it |

---

## 🔁 Approach 1: Boolean DP (Win/Lose)

### ✅ Problem: Divisor Game

- Alice and Bob take turns.
- A player loses if no valid move.
- Return `true` if Alice wins.

### 🧠 DP Strategy:
Let `dp[n] = true` if the current player can win with `n`.

```cpp
bool divisorGame(int n) {
    vector<bool> dp(n + 1, false);
    dp[1] = false;

    for (int i = 2; i <= n; i++) {
        for (int x = 1; x < i; x++) {
            if (i % x == 0 && !dp[i - x]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
````

### 🔗 Problem Link:

[LeetCode – Divisor Game](https://leetcode.com/problems/divisor-game)

---

## 🔁 Approach 2: Score-Based DP (Optimal Play)

### ✅ Problem: Stone Game

* You and opponent pick stones from either end.
* Maximize your score.
* Return `true` if you can win.

### 🧠 DP Strategy:

Let `dp[i][j] = max stones you can pick from subarray [i...j]`.

```cpp
bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        dp[i][i] = piles[i];

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        }
    }

    return dp[0][n - 1] > 0;
}
```

### 🔗 Problem Link:

[LeetCode – Stone Game](https://leetcode.com/problems/stone-game)

---

## ⚔️ Who’s Turn Is It?

* Use **difference of scores** to model alternating turns
* In `dp[i][j]`, assume:

  * `+score` if it's **your** turn
  * `-score` if it's **opponent’s** turn

This lets the problem work with **just one DP table** and alternate advantage.

---

## 🧪 More Practice Problems

| Problem               | Link                                                         |
| --------------------- | ------------------------------------------------------------ |
| ✅ Divisor Game        | [LeetCode](https://leetcode.com/problems/divisor-game)       |
| ✅ Stone Game          | [LeetCode](https://leetcode.com/problems/stone-game)         |
| 🔥 Stone Game II      | [LeetCode](https://leetcode.com/problems/stone-game-ii)      |
| 🔥 Predict the Winner | [LeetCode](https://leetcode.com/problems/predict-the-winner) |
| 🔥 Nim Game           | [LeetCode](https://leetcode.com/problems/nim-game)           |
| 🔥 Take K of N Stones | [GFG](https://www.geeksforgeeks.org/g-game/)                 |

---

## 🔍 Final Tips

* Think recursively: *What move will leave your opponent in the worst spot?*
* Use `dp[i][j]` when subproblems shrink from both ends
* Greedy won’t always work — **model with advantage difference**

---

## 📺 Bonus Resources

* [Codeforces Game Theory Guide](https://codeforces.com/blog/entry/66075)
* [NeetCode – Game Theory Problems](https://neetcode.io/roadmap)

---

### 🎯 TL;DR

If both players play optimally:

* Use **Min/Max DP** strategy
* Try to **simulate turns with score difference**
* Focus on **who makes the move**, not just the values
