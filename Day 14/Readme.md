# 🧮 Notes on `Matrix` in C++

---

## 📌 1. Basics of Matrices in C++

A **matrix** is a 2D array commonly used for representing grids, images, graphs (adjacency matrix), and more.

### ✅ Declaration

```cpp
int matrix[rows][cols];  // Static
vector<vector<int>> matrix(rows, vector<int>(cols, 0));  // Dynamic with default 0s
```

---

## 📐 2. Common Operations

| Operation                | Code Snippet                                                    |
| ------------------------ | --------------------------------------------------------------- |
| Access element at (i, j) | `matrix[i][j]`                                                  |
| Row-wise traversal       | `for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++)` |
| Column-wise traversal    | `for (int j = 0; j < cols; j++) for (int i = 0; i < rows; i++)` |
| Diagonal traversal       | `i == j` (main), `i + j == n - 1` (anti-diagonal)               |
| Transpose                | `transpose[i][j] = matrix[j][i];`                               |

---

## ⏱️ 3. Time & Space Complexity

| Operation               | Time Complexity | Space Complexity | Remarks                              |
| ----------------------- | --------------- | ---------------- | ------------------------------------ |
| Traverse Matrix         | O(n × m)        | O(1)             | Standard row/column traversal        |
| Transpose               | O(n × m)        | O(n × m)         | May require a new matrix             |
| Rotate 90° (in place)   | O(n × n)        | O(1)             | Only possible for square matrices    |
| Search in Sorted Matrix | O(n + m)        | O(1)             | Top-right or bottom-left start point |

---

## 🔍 4. Searching in a Sorted Matrix

For a matrix where rows and columns are sorted:

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size() - 1;
    while (r < matrix.size() && c >= 0) {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] < target) r++;
        else c--;
    }
    return false;
}
```

> ✅ Efficient: `O(n + m)` time instead of binary search on every row.

---

## 🔁 5. Traversal Patterns

### 🔸 Row-wise Traversal

```cpp
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        cout << matrix[i][j] << " ";
```

### 🔸 Spiral Order Traversal

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
        left++;
    }
    return res;
}
```

---

## ⚠️ Common Pitfalls

* Accessing out-of-bounds index: Always check `matrix.size()` and `matrix[0].size()` before iterating.
* Forgetting to initialize inner vectors when resizing or creating a 2D vector dynamically.
* Assuming all rows have the same number of columns—this may not hold for jagged matrices.

---

## 📘 Practice Problems

| Problem                           | Link                                                          |
| --------------------------------- | ------------------------------------------------------------- |
| Search a 2D Matrix                | [LeetCode](https://leetcode.com/problems/search-a-2d-matrix/) |
| Set Matrix Zeroes                 | [LeetCode](https://leetcode.com/problems/set-matrix-zeroes/)  |
| Spiral Matrix                     | [LeetCode](https://leetcode.com/problems/spiral-matrix/)      |
| Rotate Image (90°)                | [LeetCode](https://leetcode.com/problems/rotate-image/)       |
| Transpose Matrix                  | [LeetCode](https://leetcode.com/problems/transpose-matrix/)   |
| Number of Islands (DFS on Matrix) | [LeetCode](https://leetcode.com/problems/number-of-islands/)  |

---

## 📚 Glossary

* 🔹 **Transpose**: Flip rows and columns. `transpose[i][j] = matrix[j][i]`
* 🔹 **Spiral Order**: Traverse the matrix in a clockwise square pattern.
* 🔹 **In-place Rotation**: Rotate elements without extra space.

---
