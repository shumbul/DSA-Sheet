class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size()==0)
            return {};
        if (original.size()!=(long)m*(long)n)
            return {}; //elements are more or less than required
        vector<vector<int>> ans(m, vector<int>(n));
        int idx=0; //index of 1D array
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                ans[i][j]=original[idx];
                idx++;
            }
        }
        return ans;
    }
};
//TC O(n*m)
//SC O(n*m)
