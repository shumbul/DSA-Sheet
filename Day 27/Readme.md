# ✅ 2D Dynamic Programming – Mastering Grid-Based DP

---

## 🧠 What Is 2D DP?

2D Dynamic Programming involves solving problems where **state depends on two parameters**, commonly indices in a matrix or subproblem dimensions.

### Typical Forms:
- `dp[i][j]` represents the best solution from `(0,0)` to `(i,j)`
- `dp[i][j]` can also mean something like: "minimum cost to reach cell `(i,j)`"

---

## 🧱 Common Use Cases

| Category                  | Examples                                                          |
|---------------------------|-------------------------------------------------------------------|
| Grid Traversal            | Minimum Path Sum, Unique Paths                                   |
| Substring/Subsequence     | Longest Common Subsequence, Edit Distance, Palindromic Substring |
| Knapsack-Like Problems    | 0/1 Knapsack, Partition Equal Subset Sum                         |
| Matching/Conversion       | Regex Matching, Wildcard Matching                                |

---

## 🔁 Template: Grid Traversal DP

```cpp
int m = grid.size(), n = grid[0].size();
vector<vector<int>> dp(m, vector<int>(n, 0));

dp[0][0] = grid[0][0]; // base case

for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
        if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
    }
}
return dp[m-1][n-1];
````

---

## 🧵 Template: Subsequence DP

```cpp
// LCS of s1[0..i-1] and s2[0..j-1]
vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
```

---

## 🔥 Common Patterns & Tips

| Pattern             | Insight                                                       |
| ------------------- | ------------------------------------------------------------- |
| Top-Down (Memo)     | Use `dp[i][j]` with recursion + cache                         |
| Bottom-Up (Tabular) | Fill from base case using loops                               |
| Diagonal Traversal  | For palindromes or subsequences                               |
| Space Optimization  | Reduce from `dp[i][j]` to just 2 rows if only previous needed |

---

## 📚 Must-Practice 2D DP Problems

| Problem Name               | Link                                                                  | Concepts Involved             |
| -------------------------- | --------------------------------------------------------------------- | ----------------------------- |
| Unique Paths               | [LeetCode](https://leetcode.com/problems/unique-paths/)               | Grid Traversal, Combinatorics |
| Minimum Path Sum           | [LeetCode](https://leetcode.com/problems/minimum-path-sum/)           | Grid DP, Bottom-Up            |
| Longest Common Subsequence | [LeetCode](https://leetcode.com/problems/longest-common-subsequence)  | DP on Strings                 |
| Edit Distance              | [LeetCode](https://leetcode.com/problems/edit-distance/)              | Insert/Delete/Replace DP      |
| 0/1 Knapsack               | [GFG](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)      | DP on Weight & Items          |
| Palindromic Substrings     | [LeetCode](https://leetcode.com/problems/palindromic-substrings/)     | DP on i, j (range)            |
| Partition Equal Subset Sum | [LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/) | 1D DP, Subset Sum             |

---

## 🧠 Visualization Help

* `dp[i][j]` = Result at (i, j) in matrix/grid
* Fill row-by-row or column-by-column
* Debug by printing intermediate DP table

---

## 📌 TL;DR

* Use **2D DP** when the problem has **two dimensions**: grid, string pairs, or ranges.
* Carefully define what `dp[i][j]` means.
* Always **start from base cases**, then build up with proper transitions.

---

## 📺 Bonus Resources

* [Aditya Verma – DP Playlist](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
* [NeetCode – Top 2D DP Patterns](https://www.youtube.com/@NeetCode) 
