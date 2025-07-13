class Solution {
    int dx[4] = {0, 1, 0, -1}; // right, down, left, up
    int dy[4] = {1, 0, -1, 0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;  // variable to store maximum island area
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) 
                { //If the current cell is land (1) and unvisited, it's part of an island 
                    int area = dfs(grid, i, j, n, m); //// compute area of this island
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 1) //if the cell is out of bounds or not land 
            return 0;
        grid[row][col] = 0; // mark cell as visited by converting to water
        int area = 1;       // current cell counts as 1
        for (int i = 0; i < 4; ++i) {
            area += dfs(grid, row + dx[i], col + dy[i], n, m); // explore 4 directions
        }
        return area;
    }
};
