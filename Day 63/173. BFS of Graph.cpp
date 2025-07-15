class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int, vector<int>> nodes;
        queue<int> traverse;
        set<int> visited;
        vector<int> ans;
        for (int i=0;i<adj.size();i++)
        {
            nodes[i]=adj[i];
        }
        traverse.push(0);
        visited.insert(0);
        while (!traverse.empty())
        {
            int frontt=traverse.front();
            //cout<<"frontt"<<frontt<<endl;
            traverse.pop();
            
            ans.push_back(frontt);
            for (int i:nodes[frontt])
            {
                if (visited.find(i)==visited.end())
                {
                    //cout<<i<<" ";
                traverse.push(i);
                visited.insert(i);
                }
            }
            
        }
        // for (int i:visited)
        // ans.push_back(i);
        return ans;
    }
};
