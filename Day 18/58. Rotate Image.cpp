class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<n/2;i++) //swaps rows from top to bottom i.e. swap the 1st half of the rows with the 2nd half
        {
            for (int j=0;j<n;j++)
            {
                int newi=n-1-i;
                swap(matrix[i][j], matrix[newi][j]);
            }
        }
         for (int i=0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]); //transpose
            }
        }
    }
};
