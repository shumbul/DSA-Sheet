class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        return helper(0, 0, grid);
    }
    int helper(int x, int y, vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        // if we're at the last cell
        if (x == m - 1 && y == n - 1)
            return grid[x][y];
        // If we're out of bounds
        if (x >= m || y >= n)
            return INT_MAX;
        // Choose min path from right and down
        int right = helper(x, y + 1, grid);
        int down = helper(x + 1, y, grid);
        return grid[x][y] + min(right, down);
    }
};
//TC O(2^(m+n))
//SC O(m+n)

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, grid, dp);
    }
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if (x == m - 1 && y == n - 1) //base case
            return grid[x][y];
        if (x >= m || y >= n) //out of bounds
            return INT_MAX;
        if (dp[x][y] != -1) //already computed
            return dp[x][y];
        int right = helper(x, y + 1, grid, dp);
        int down = helper(x + 1, y, grid, dp);
        return dp[x][y] = grid[x][y] + min(right, down); //min path
    }
};
