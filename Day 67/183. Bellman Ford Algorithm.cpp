//https://www.youtube.com/watch?v=lyw4FaxrwHg&ab_channel=WilliamFiset
//https://www.youtube.com/watch?v=B5PmlJACZ9Y&ab_channel=ByteQuest

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX); // Use a large value to represent infinity
        dist[src] = 0;
        // Step 1: Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
          //we do V-1 iterations of edge relaxation. Because in a graph with V vertices, the longest possible simple path has at most V−1 edges.
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Step 2: Check for negative weight cycles
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                // Any further improvement means there’s a cycle that can keep reducing the path cost — and that’s only possible if there’s a negative weight cycle.
                //this reduction should NOT happen. means there is a cycle of negative weight that allows the path to keep getting cheaper forever → invalid for shortest path algorithms.
                return {-1};
            }
        }
        return dist;
    }
};
