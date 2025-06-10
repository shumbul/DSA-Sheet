class Solution {
    vector<vector<int>> ans;
    vector<int> temp={1};
public:
    vector<vector<int>> generate(int numRows) {
        ans.push_back(temp);
        for (int i=2;i<=numRows;i++)
        {
            ans.push_back(helper(numRows));
        }
        return ans;
    }
    vector<int> helper(int numRows)
    {
        if (numRows==1)
            return {1};
        vector<int> temp2;
        temp2.push_back(1);
        for (int i=0;i<temp.size()-1;i++)
        {
            temp2.push_back(temp[i]+temp[i+1]);
        }
        temp2.push_back(1);
        temp=temp2;
        return temp2;
    }
};

class Solution {
    vector<vector<int>> ans;
    vector<int> temp={1};
public:
    vector<vector<int>> generate(int numRows) {
        ans.push_back(temp);
         helper(1, numRows);
        return ans;
    }
    vector<int> helper(int curr, int numRows)
    {
        if (numRows==1)
            return {1};
        if (curr==numRows)
            return {};
        vector<int> temp2;
        temp2.push_back(1);
        for (int i=0;i<temp.size()-1;i++)
        {
            temp2.push_back(temp[i]+temp[i+1]);
        }
        temp2.push_back(1);
        ans.push_back(temp2);
        temp=temp2;
        helper(curr+1, numRows);
        return temp2;
    }
};

class Solution {
    vector<vector<int>> dp;  // Memoization table
public:
    vector<vector<int>> generate(int numRows) {
        dp.resize(numRows, vector<int>(numRows, -1));  // Fill with -1 to indicate uncomputed
        vector<vector<int>> ans;
        for (int r = 0; r < numRows; ++r) {
            vector<int> row;
            for (int c = 0; c <= r; ++c) {
                row.push_back(getValue(r, c));
            }
            ans.push_back(row);
        }
        return ans;
    }
    int getValue(int r, int c) {
        if (c == 0 || c == r)
            return 1;
        if (dp[r][c] != -1)
            return dp[r][c];
        return dp[r][c] = getValue(r - 1, c - 1) + getValue(r - 1, c);
    }
};
