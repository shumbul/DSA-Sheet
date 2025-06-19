class Solution {
    vector<vector<int>> dp;
public:
    vector<int> getRow(int numRows) {
        dp.resize(numRows+1, vector<int>(numRows+1, -1));  // Fill with -1 to indicate uncomputed
        vector<int> ans;
        for (int r = 0; r <=numRows; ++r) {
            vector<int> row;
            for (int c = 0; c <= r; ++c) {
                row.push_back(getValue(r, c));
            }
            ans=row;
        }
        return ans;
    }
    int getValue(int r, int c) {
        if (c == 0 || c == r) //1st and last elements of each row are always 1
            return 1;
        if (dp[r][c] != -1)
            return dp[r][c];
        dp[r][c] = getValue(r - 1, c - 1) + getValue(r - 1, c);
        //add the two nos directly above it in the triangle — one from left and other from right
        return dp[r][c];
    }
};
//TC O(N^2)
//SC O(N^2)
