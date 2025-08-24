//https://www.youtube.com/watch?v=QlGuaHT1lzA&ab_channel=BasicsStrong

/*Find Strongly Connected Components (SCCs) in a directed graph.
An SCC is a maximal set of nodes such that every node is reachable from every other node in the set.
A node that finishes last in DFS of the original graph cannot reach any unvisited node outside its SCC.
If we reverse the graph and run DFS in the order of decreasing finishing times, each DFS will explore exactly one SCC.*/
class Solution {
  public:
    // First DFS to calculate finishing times
    void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        visited[node] = true; // Mark current node as visited
        // Explore all neighbors of the current node
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs1(neigh, adj, visited, st); // Recursively visit unvisited neighbors
            }
        }
        st.push(node); // After visiting all descendants, push node to stack
    }
    // Second DFS on reversed graph
    void dfs2(int node, vector<vector<int>> &rev, vector<bool> &visited) {
        visited[node] = true; // Mark current node as visited in reversed graph
        // Explore all neighbors in reversed graph
        for (int neigh : rev[node]) {
            if (!visited[neigh]) {
                dfs2(neigh, rev, visited); // Recursively visit unvisited neighbors
            }
        }
        // No need to push to stack here; each DFS call marks a full SCC
    }
    // Kosaraju's algorithm main function
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size(); // Number of vertices in the graph
        // Step 1: Run DFS to fill stack with finishing times
        vector<bool> visited(V, false); // Track visited nodes
        stack<int> st;                  // Stack to store finishing order
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st); // Fill stack with DFS finishing times
            }
        }
        // Step 2: Reverse the graph
        vector<vector<int>> rev(V); // Reversed adjacency list
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                rev[v].push_back(u); // Reverse the direction of every edge
            }
        }
        // Step 3: DFS on reversed graph in order of stack (finishing times)
        fill(visited.begin(), visited.end(), false); // Reset visited for second DFS
        int scc_count = 0; // Initialize count of strongly connected components
        while (!st.empty()) {
            int node = st.top();
            st.pop(); // Get the next node in finishing order
            if (!visited[node]) {
                dfs2(node, rev, visited); // Visit all nodes in this SCC
                scc_count++;              // Completed one SCC
            }
        }
        return scc_count; // Return total number of SCCs
    }
};
//TC O(V+E)

