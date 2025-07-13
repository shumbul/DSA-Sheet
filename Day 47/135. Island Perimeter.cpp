class Solution {
    int sum=0; // Stores total perimeter
    int dx[4]={-1, 0, 1, 0};
    int dy[4]={0, 1, 0, -1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if (grid[i][j]==1)
                    helper(i,j,grid); //If the cell is land (1), we calculate how many sides contribute to the perimeter.
            }
        }
        return sum;
    }
    void helper(int row, int col, vector<vector<int>>& grid)
    { //checks all 4 neighbors of the land cell
        for (int k=0;k<4;k++)
        {
            int newrow=row+dx[k];
            int newcol=col+dy[k];
            if ((newrow>=0 && newrow<grid.size()) && (newcol>=0 && newcol<grid[0].size()))
            { //If the neighbor is within bounds, and it is water (0) → that side contributes +1 to the perimeter.
                if (grid[newrow][newcol]==0)
                    sum++;
            }
            else //If the neighbor is out of bounds, that side is exposed, so it also adds +1 to the perimeter.
                sum++;
        }
    }
};
//TC O(N*M)
//SC O(1)
