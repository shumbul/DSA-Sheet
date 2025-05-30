class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        //current matrix boumdaries
        int n = matrix.size(); 
        int m = matrix[0].size();
        //current spiral layer
        int strow = 0;
        int stcol = 0;
        while (strow < n && stcol < m) { //first row
            for (int i = stcol; i < m; i++) {
                ans.push_back(matrix[strow][i]); //stcol to m-1
            }
            strow++; //move down
            for (int i = strow; i < n; i++) { //last column
                ans.push_back(matrix[i][m - 1]); //strow to n-1
            }
            m--; //move left
            for (int i = m - 1; i >= stcol; i--) { //last row
                ans.push_back(matrix[n - 1][i]); //m-1 to stcol
            }
            n--; //move up
            for (int i = n - 1; i >= strow; i--) { //first column
                ans.push_back(matrix[i][stcol]); //n-1 to strow
            }
            stcol++; //move right
        }
        ans.resize((long)matrix.size()*(long)matrix[0].size()); //ensures ans has correct size
        return ans;
    }
};
//TC O(n*m)
//SC O(1)
