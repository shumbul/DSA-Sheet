class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != '1') //If the current cell is out of bounds or not land ('1')
            return;
        grid[row][col] = '0'; //so we don’t visit it again
        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dx[i], col + dy[i]);
        }
    }
};
//TC O(M*N)
//SC O(M*N)
