//dfs
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        // Convert matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        // BFS traversal for each unvisited node
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                bfs(i, visited, adj);
                count++;  // found a new province
            }
        }
        return count;
    }
    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        visited[node] = 1;
        q.push(node);
        while (!q.empty()) {
            int frontt = q.front();
            q.pop();
            //  get the correct neighbors
            for (int nbr : adj[frontt]) {
                if (visited[nbr] == 0) {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
    }
};
