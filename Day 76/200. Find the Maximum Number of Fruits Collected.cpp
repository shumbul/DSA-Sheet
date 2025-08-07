class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0; //total fruits collected
        for (int i = 0; i < n; i++) { //Adds all values along the main diagonal (from top-left to bottom-right) to the result. This represents fruits collected along the diagonal path
            res += grid[i][i];
        }
        for (int pass = 0; pass < 2; pass++) { //Runs the main algorithm twice - once for each of two additional paths
            if (pass == 1) { //On the second pass, transposes the grid (swaps rows and columns). This allows using the same algorithm for both the upper-right and lower-left triangular regions
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }
            vector<int> prev(n, -1); //stores the maximum fruits collectible at each column in the previous row
            vector<int> curr(n, -1); //stores the maximum fruits collectible at each column in the current row
            prev[n - 1] = grid[0][n - 1]; //Sets the starting position: top-right corner for first pass, or top-right of transposed grid for second pass
            for(int row = 1; row < n - 1; row++) { //excluding first and last rows
                fill(curr.begin(), curr.end(), -1); //Resets all positions in current row to -1 (unreachable)
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) //For each column position, skip if it was unreachable in the previous row
                         continue;
                    if (i > 0) 
                        curr[i - 1] = max(curr[i - 1], prev[i] + grid[row][i - 1]);
                    if (i < n - 1) 
                        curr[i + 1] = max(curr[i + 1], prev[i] + grid[row][i + 1]);
                    curr[i] = max(curr[i], prev[i] + grid[row][i]);
                }
                swap(prev, curr);
            }
            res += prev[n - 1]; //Add the maximum fruits collectible at the bottom-right corner to the total result
        }
        return res;
    }
};
