class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap to store {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false);
        int sum = 0;
        pq.push({0, 0}); // weight = 0, node = 0
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            sum += wt;
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        return sum;
    }
};
