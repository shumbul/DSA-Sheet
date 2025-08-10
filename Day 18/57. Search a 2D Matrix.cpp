class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;  // Start at top-right
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } 
            else if (matrix[row][col] > target) {
                col--; // move left
            } 
            else {
                row++; // move down
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0; //to track the row where the target might be found
        int m=matrix[0].size();
        int n=matrix.size();
        for (int i=0;i<n;i++)
        {
            if (target<=matrix[i][m-1]) //finds the first row where last element of the row >= target. If the last element is < target, the target cannot be in that row. If the last element is >= target, then target may be in this row
            {
                row=i;
                break;
            }
        }
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};
//TC O(nlog(m*n))
