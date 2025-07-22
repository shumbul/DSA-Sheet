//https://youtu.be/EFg3u_E6eHU
//https://www.youtube.com/watch?v=CmIQ29cUGiE&ab_channel=ByteQuest

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(V); //Each adj[u] contains a list of {v, wt} pairs, where there is an edge from u to v with weight wt
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(V, INT_MAX); //stores the shortest distance from src to every vertex.
        vector<bool> visited(V, false); //shortest distance to a node is known or not
        dist[src] = 0;
        for (int i = 0; i < V; i++) {
            int u = -1; //we haven't picked any node yet.
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) { //if j is closer to the source than our current best u
                    u = j;
                }
            }
            if (dist[u] == INT_MAX) //If the smallest unvisited node is still at infinite distance, it means remaining nodes are unreachable
                break;
            visited[u] = true; //its shortest path is now finalized
            for (auto p : adj[u]) {
                int v = p.first;
                int wt = p.second;
                if (!visited[v] && dist[u] + wt < dist[v]) { //if going through u to reach v is shorter than the current known path to v
                 /*you are at node u. There’s an edge from u to v with weight wt.
                   You already know the shortest distance from the source to u → that's dist[u].
                   So, the cost to reach v via u is: dist[u] + wt.
                   Now compare it to your current known distance to v → dist[v]*/
                  dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};
