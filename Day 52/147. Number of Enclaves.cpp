class Solution {
    int dx[4] = {0, 1, 0, -1}; // direction arrays to move right, down, left, up
    int dy[4] = {1, 0, -1, 0};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();         // number of rows
        int m = grid[0].size();      // number of columns
        // Step 1: DFS from all land cells connected to the boundary
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)              // left boundary
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)          // right boundary
                dfs(grid, i, m - 1, n, m);
        }
        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == 1)              // top boundary
                dfs(grid, 0, j, n, m);
            if (grid[n - 1][j] == 1)          // bottom boundary
                dfs(grid, n - 1, j, n, m);
        }
        // Step 2: Count remaining land cells (enclaves)
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)          // still land and not connected to edge
                    count++;
            }
        }
        return count; // number of enclave land cells
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 1)
            return; // invalid cell or already visited/water
        grid[row][col] = 0; // mark land as water to prevent revisiting
        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dx[i], col + dy[i], n, m); // explore 4 directions
        }
    }
};
//TC O(m*n)
//SC O(m*n)
