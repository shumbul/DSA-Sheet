class Solution {
public:
    int cnt = 0; // keep track of the number of nodes whose cost is increased to equalize all root-to-leaf path scores.
    vector<vector<int>> adj; //adjacency list representation of the tree.
    long long dfs(int node, int parent, const vector<int>& cost) 
    { //Computes the maximum cost path from the current node down to a leaf and counts how many children need to be increased to make all paths the same length.
        vector<long long> childSums; //Stores the total cost (from child to leaf) for each child of the current node.
        for (int nei : adj[node]) {
            if (nei == parent) 
                continue; //skip it (prevents revisiting).
            long long child = dfs(nei, node, cost); //get the total cost from this child to its leaf.
            childSums.push_back(child);
        }
        if (childSums.empty()) { //If the node is a leaf (no children besides parent), return its own cost — it's the base of the path.
            return cost[node];
        }
        long long maxChild = *max_element(childSums.begin(), childSums.end()); //This maximum cost among all child paths is the target that all child paths must match by increasing costs where needed.
        // For each child with lesser path sum, we need to increase that child
        for (long long sum : childSums) {
            if (sum < maxChild) {
                cnt++;  // We optimistically assume we can do this by increasing only one node in that subtree (greedy at child)
            }
        }
        return cost[node] + maxChild; //total cost of the current node's path to a leaf
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) 
    { //Returns the minimum no. of nodes to be increased
        adj.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, cost);
        return cnt;
    }
};
//TC O(N)
//SC O(N)
