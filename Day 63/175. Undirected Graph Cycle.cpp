class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, set<int>> nodes;
        set<int> visited;
        queue<int> traverse;
        for (int i=0;i<edges.size();i++)
        {
            nodes[edges[i][0]].insert(edges[i][1]);
            nodes[edges[i][1]].insert(edges[i][0]);
        }
        traverse.push(0);
        while (!traverse.empty())
        {
            int frontt=traverse.front();
            traverse.pop();
            if (visited.find(frontt)!=visited.end())
                return true;
            visited.insert(frontt);
            for (int i:nodes[frontt])
            {
                traverse.push(i);
            }
        }
        return false;
    }
};
