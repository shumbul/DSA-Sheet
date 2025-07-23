## ✅ DFS Simplified in C++

### 🔍 What is DFS?

**Depth-First Search (DFS)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking.

* **Works well for:** Topological sorting, cycle detection, connected components.
* **Key Data Structure:** Recursion stack or explicit stack (LIFO)

---

### 🧠 Real-Life Analogy

Imagine exploring a maze: you keep going forward until you hit a wall, then backtrack to the last decision point and try a new path. That’s DFS.

---

### 🛠️ DFS Template in C++ (Graph)

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
```

---

### 📦 DFS Template for Grid (2D Matrix)

```cpp
void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;

    grid[i][j] = '0'; // mark visited

    dfs(i + 1, j, grid, n, m);
    dfs(i - 1, j, grid, n, m);
    dfs(i, j + 1, grid, n, m);
    dfs(i, j - 1, grid, n, m);
}
```

---

### 🌳 DFS Template for Trees

```cpp
void dfsTree(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    dfsTree(root->left);
    dfsTree(root->right);
}
```

---

### 🧠 Key Concepts Table:

| Concept              | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| **Recursion/Stack**  | DFS uses the call stack (or manually with an explicit stack) |
| **Backtracking**     | DFS explores deep paths and backtracks                       |
| **Space Complexity** | O(h) for trees (h = height), O(V) for graphs                 |
| **Time Complexity**  | O(V + E) where V = vertices, E = edges                       |
| **Cycle Detection**  | DFS with visited and parent tracking or coloring             |

---

### 🧪 5 Beginner DFS Problems

| No. | Question               | Link                                                                                        | Topic      |
| --- | ---------------------- | ------------------------------------------------------------------------------------------- | ---------- |
| 1   | 01. DFS of Graph       | [GeeksforGeeks](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1) | Graph, DFS |
| 2   | 02. Flood Fill         | [LeetCode](https://leetcode.com/problems/flood-fill/)                                       | Grid, DFS  |
| 3   | 03. Number of Islands  | [LeetCode](https://leetcode.com/problems/number-of-islands/)                                | Grid, DFS  |
| 4   | 04. Max Area of Island | [LeetCode](https://leetcode.com/problems/max-area-of-island/)                               | Grid, DFS  |
| 5   | 05. Path Sum           | [LeetCode](https://leetcode.com/problems/path-sum/)                                         | Tree, DFS  |

---

### 📌 Applications of DFS:

* **Connected Components** in graphs
* **Cycle Detection** in directed/undirected graphs
* **Topological Sorting** in DAGs
* **Backtracking** (e.g. Sudoku, N-Queens)
* **Maze solving**, finding any path
* **Tree traversals** (Inorder, Preorder, Postorder)

---
