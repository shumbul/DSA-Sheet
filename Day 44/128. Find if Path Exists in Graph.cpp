class Solution {
    set<int> visited;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source==destination)
             return true; //path trivially exists
        unordered_map<int, vector<int>> paths;
        for (int i=0;i<edges.size();i++)
        {
            //because this is bidirectional
            paths[edges[i][0]].push_back(edges[i][1]);
            paths[edges[i][1]].push_back(edges[i][0]);
        }
        return helper(source, paths, destination);
    }
    bool helper(int node, unordered_map<int, vector<int>>& paths, int dest)
    {
        if (visited.find(node)==visited.end())
        {
            for (auto neighbours:paths[node])
            {
                //for (int i:neighbours.second)
                {
                    visited.insert(node);
                    helper(neighbours, paths, dest);  
                }  
            }
        }
        else
            return false;
        return visited.find(dest)!=visited.end();
        //check if we have reached dest
    }
};
/*TC
Building adjacency list: O(E) Each edge is added twice.
DFS Traversal: O(V + E) You visit every node and edge at most once.
Total: O(V + E)
SC
Adjacency list: O(V + E)
Visited set: O(V)
Call stack (DFS recursion): O(V) 
Total : O(V + E)*/
