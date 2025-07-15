class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        set<int> visited;
        dfs(0, adj, ans, visited);
        return ans;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& ans, set<int>& visited){
        ans.push_back(node); //Add the current node to ans since we are now visiting it
        visited.insert(node);
        for(int nbr: adj[node])
        { //Iterate over all adjacent nodes (nbr) of the current node
            if(!visited.count(nbr))
                dfs(nbr, adj, ans, visited);
        }
    }
};
