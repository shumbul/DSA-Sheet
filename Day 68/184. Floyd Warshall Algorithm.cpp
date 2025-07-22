//https://www.youtube.com/watch?v=sLg6Leb-xt0&ab_channel=ByteQuest

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        int INF = 1e8;  // or INT_MAX / 2, to prevent overflow during addition
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};
