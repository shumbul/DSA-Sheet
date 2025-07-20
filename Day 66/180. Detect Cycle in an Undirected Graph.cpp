//DFS
class Solution {
    set<int> visited;
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
       vector<vector<int>>graph; //adjacency list
       graph=constructGraph(V, edges);
       for (int i=0;i<V;i++) //ensure disconnected components are also checked.
       {
           if (visited.find(i)==visited.end())
           {
               visited.insert(i);
               if (dfscycle(i, -1, graph))
                    return true;
           }
       }
       return false;
    }
    bool dfscycle(int node, int parent, vector<vector<int>>& graph)
    { //returns true if there is a cycle
        for (int nbr:graph[node])
        {
            if (visited.find(nbr)==visited.end())
            {
                visited.insert(nbr);
                if (dfscycle(nbr, node, graph))
                    return true;
            }
            
            else if (nbr!=parent) 
            {//If neighbor is already visited but not the parent of current node It means we’ve found a back edge ➝ cycle detected
              //I've found a neighbor that I’ve already visited, and it’s not the node I came from — this is a cycle
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> constructGraph(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>>graph(V);
        for (int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return graph;
    }
};

//BFS
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph = constructGraph(V, edges);
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCycle(i, graph, visited))
                    return true;
            }
        }
        return false;
    }
    bool bfsCycle(int src, vector<vector<int>>& graph, vector<bool>& visited) {
        queue<pair<int, int>> q; // pair<node, parent>
        visited[src] = true; //Mark the starting node as visited.
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int nbr : graph[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, node});
                } else if (nbr != parent) {
                    // visited and not parent => cycle
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> constructGraph(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return graph;
    }
};
