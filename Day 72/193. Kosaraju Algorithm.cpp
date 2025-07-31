//https://www.youtube.com/watch?v=QlGuaHT1lzA&ab_channel=BasicsStrong

class Solution {
  public:
    void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) 
    { //Marks nodes in post-order (used to order DFS on reversed graph).
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs1(neigh, adj, visited, st);
            }
        }
        st.push(node); // push after exploring all descendants. This preserves finishing order.
    }
    void dfs2(int node, vector<vector<int>> &rev, vector<bool> &visited) 
    { //Traverse one (SCC) in the reversed graph.
        visited[node] = true;
        for (int neigh : rev[node]) {
            if (!visited[neigh]) {
                dfs2(neigh, rev, visited);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size(); // Number of vertices
        // Step 1: First DFS to get finishing times
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }
        // Step 2: Reverse the graph
        vector<vector<int>> rev(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                rev[v].push_back(u); // reverse the edge
            }
        }
        // Step 3: DFS on reversed graph in finishing order
        fill(visited.begin(), visited.end(), false); //reset visited
        int scc_count = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                dfs2(node, rev, visited);
                scc_count++; // one SCC completed
            }
        }
        return scc_count;
    }
};
