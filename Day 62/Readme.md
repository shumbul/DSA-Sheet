## 🔄 Breadth-First Search (BFS) in C++ – Complete Guide

Breadth-First Search (BFS) is a **graph traversal** algorithm used to explore all vertices of a graph or tree level by level. It's particularly useful for:
- Finding the shortest path in unweighted graphs
- Exploring neighbors before going deeper
- Solving problems involving **grids**, **trees**, or **graphs**

---

### 🧠 BFS Basics

- **Traversal Type**: Level-by-level (or breadth-first)
- **Data Structure Used**: Queue (FIFO)
- **Key Operations**: Push current node → Mark visited → Explore neighbors

---

### 📦 Template: BFS for Graph (Adjacency List)

```cpp
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Process node
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
````

---

### 📦 Template: BFS for Grid (4-directional)

```cpp
int rows = grid.size(), cols = grid[0].size();
vector<vector<bool>> visited(rows, vector<bool>(cols, false));
queue<pair<int, int>> q;
vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // Up, Down, Left, Right

q.push({startX, startY});
visited[startX][startY] = true;

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;

        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
            !visited[nx][ny] && grid[nx][ny] == 1) {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}
```

---

### 🧮 Applications of BFS

| Problem Type                     | How BFS Helps                       |
| -------------------------------- | ----------------------------------- |
| Shortest path (unweighted graph) | Finds minimum steps                 |
| Tree level traversal             | Traverses tree layer by layer       |
| Grid/Matrix                      | Spreads across connected components |
| Multi-source BFS                 | Process all sources together        |

---

### 💡 Multi-Source BFS Example

```cpp
queue<pair<int, int>> q;

// Push all starting points
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
            q.push({i, j});
        }
    }
}
```

---

### 🔍 Common Mistakes to Avoid

* ❌ Forgetting to mark nodes as visited → Infinite loop
* ❌ Not checking bounds in a grid
* ❌ Revisiting already visited nodes

---

### ✅ 5 Easy-Level Problems to Practice BFS

| No. | Question                                 | Link                                                                          | Tags        |
| --- | ---------------------------------------- | ----------------------------------------------------------------------------- | ----------- |
| 1   | 733. Flood Fill                          | [LeetCode](https://leetcode.com/problems/flood-fill/)                         | Matrix, BFS |
| 2   | 542. 01 Matrix                           | [LeetCode](https://leetcode.com/problems/01-matrix/)                          | Grid, BFS   |
| 3   | 994. Rotting Oranges                     | [LeetCode](https://leetcode.com/problems/rotting-oranges/)                    | BFS, Grid   |
| 4   | 785. Is Graph Bipartite?                 | [LeetCode](https://leetcode.com/problems/is-graph-bipartite/)                 | Graph, BFS  |
| 5   | 1926. Nearest Exit from Entrance in Maze | [LeetCode](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/) | Grid, BFS   |

---

### 📌 Tip for Interviews

When solving grid/graph problems:

* Use BFS when you want the **shortest path** or **minimum moves**
* Use DFS when you want to **explore all paths/components**

---

### 🛠 Related Concepts

* BFS with Depth Tracking → Add a level counter in BFS loop
* Multi-source BFS → Add all sources to queue at once
* BFS for Shortest Path → Add distance tracking alongside queue

---

### 🧑‍💻 Sample Problem: Rotting Oranges (LeetCode #994)

**Problem**: Each minute, rotting oranges rot their adjacent fresh ones. Find minimum time to rot all.

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size(), fresh = 0, minutes = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
        }
    }

    vector<pair<int, int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}
```

---

### ✅ Summary Table

| Feature        | BFS                                   |
| -------------- | ------------------------------------- |
| Traversal Type | Level-order                           |
| Uses           | Queue                                 |
| Best For       | Shortest Path, Spreading Problems     |
| Pitfalls       | Missed visited checks, infinite loops |

---
