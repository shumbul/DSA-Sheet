//using a topological trimming (BFS) approach by peeling off leaves layer by layer, and the remaining nodes will be MHT roots.
class Solution {
    vector<int> indegree; //degree of each node
    unordered_map<int, set<int>> graph; //Adjacency list
    queue<int> leaves;
    set<int> visited;
    vector<int> ans; //the MHT roots.
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        indegree.resize(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) 
        { //Build the graph (adjacency list) and track the degree of each node.
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        int minind = *min_element(indegree.begin(), indegree.end());
      //Find the minimum indegree — i.e., typically 1 for a leaf. (This step is unnecessary in standard MHT solutions because all nodes with degree 1 are leaves — instead, we should just find all nodes with degree 1.)
        for (int i = 0; i < indegree.size(); i++) {
            if (minind == indegree[i]) {
                leaves.push(i); //Enqueue all nodes with minimum indegree (i.e., likely leaves) 
                visited.insert(i);
            }
        }
        while (!leaves.empty()) {
            int sizee = leaves.size();
            if (n<=2) //MHTs can have at most 2 roots, so once n <= 2, we stop.
                break;
            while (sizee--) {
                int frontt = leaves.front();
                leaves.pop();
                for (int i : graph[frontt]) {
                        graph[i].erase(frontt); //remove parent's link from child so that it doesn't visit parent again
                         if (graph[i].size()==1)
                            leaves.push(i); //If any neighbor now has only one connection, it becomes a new leaf, so we enqueue it.
                }
                n--; //we have removed one node.
            }
        }
        while (!leaves.empty())
        { //the remaining nodes in the leaves queue are the roots of Minimum Height Trees.
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};
//TC O(N)
//SC O(N)
