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
