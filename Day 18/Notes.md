# ✅ Matrix: Concepts, Notes & Patterns

---

## 🔍 What is a Matrix?

A **matrix** is a 2D array of `m` rows and `n` columns, often used to represent grids, images, game boards, graphs, etc.

In C++, it’s represented as:
```cpp
vector<vector<int>> matrix(m, vector<int>(n));
````

---

## 📌 Common Matrix Patterns

| Pattern                     | Description                                 | Use Cases                       |
| --------------------------- | ------------------------------------------- | ------------------------------- |
| Row-wise & Column-wise Loop | Basic iteration over matrix                 | Print, Search                   |
| Boundary Traversal          | Traverse top → right → bottom → left        | Spiral Matrix, Rotations        |
| DFS/BFS on Matrix           | Move in 4 or 8 directions from a cell       | Flood Fill, Number of Islands   |
| In-place Modification       | Update the matrix without using extra space | Set Matrix Zeroes, Rotate Image |
| Simulation                  | Follow step-by-step rules                   | Game of Life, Spread logic      |

---

## 🧠 Tricks & Techniques

* **Direction Arrays** for movement:

```cpp
int dx[4] = {0, 1, 0, -1};  // right, down, left, up
int dy[4] = {1, 0, -1, 0};
```

* **Boundary Checks**:

```cpp
if (x >= 0 && x < m && y >= 0 && y < n)
```

* **In-place Encoding** (used when you want to encode state change without extra space)

---

## ✏️ Quick Code Templates

### ✅ Row-wise Traversal

```cpp
for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
        cout << matrix[i][j] << \" \";
    }
}
```

### ✅ DFS on Matrix

```cpp
void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
    int m = mat.size(), n = mat[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
    visited[i][j] = true;

    dfs(i+1, j, mat, visited);
    dfs(i-1, j, mat, visited);
    dfs(i, j+1, mat, visited);
    dfs(i, j-1, mat, visited);
}
```

---

## 📚 Recommended Problems

| Problem Name       | Link                                                         |
| ------------------ | ------------------------------------------------------------ |
| Flood Fill         | [LeetCode](https://leetcode.com/problems/flood-fill)         |
| Set Matrix Zeroes  | [LeetCode](https://leetcode.com/problems/set-matrix-zeroes)  |
| Spiral Matrix      | [LeetCode](https://leetcode.com/problems/spiral-matrix)      |
| Rotate Image       | [LeetCode](https://leetcode.com/problems/rotate-image)       |
| Number of Islands  | [LeetCode](https://leetcode.com/problems/number-of-islands)  |
| Game of Life       | [LeetCode](https://leetcode.com/problems/game-of-life)       |
| Search a 2D Matrix | [LeetCode](https://leetcode.com/problems/search-a-2d-matrix) |
| Word Search        | [LeetCode](https://leetcode.com/problems/word-search)        |

---

## 🔗 Extra Resources

* [GFG Matrix Practice Set](https://www.geeksforgeeks.org/matrix-data-structure/)
* [NeetCode Matrix Playlist](https://www.youtube.com/playlist?list=PLot-Xpze53ldVwtSTzSuvMkvugR7ZKzJC)

---
