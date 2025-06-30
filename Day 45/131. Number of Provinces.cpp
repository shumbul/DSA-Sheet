class Solution {
    vector<int> visited;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        visited.resize(300, 0);
        int n=isConnected.size();
        int provinces=0;
        for (int i=0;i<n;i++)
        {
           if (!visited[i])
           {
                provinces++; // Found a new province
                dfs(isConnected, i);
           }
        }
        return provinces;
    }
    void dfs(vector<vector<int>>& isConnected, int node)
    {
        if (visited[node])
            return;
        visited[node]=true;
        for (int i=0;i<isConnected[node].size();i++)
        {
            if (!visited[i] && isConnected[node][i]!=0) //no direct connection from node to i
            {
                dfs(isConnected, i);
            }
        }
    }
};
/*
TC O(n^2) for matrix
SC O(n)+O(n)
Visited array: O(n)
Call stack (DFS recursion): O(n)
*/
