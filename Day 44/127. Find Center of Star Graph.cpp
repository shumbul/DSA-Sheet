class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> current; //to hold the nodes from the first edge
        set<int> result; //to store nodes that are common between current and all other edges
        for (int i=0;i<edges[0].size();i++)
            current.insert(edges[0][i]);
        //store first and check other edges
        for (int i=1;i<edges.size();i++)
        {
            for (int j=0;j<edges[0].size();j++)
            {
                if (current.find(edges[i][j])!=current.end())
                    result.insert(edges[i][j]);
            }
        }
        for (auto s:result)
        {
            return s; //return the first (and only) element in result
        }
        return -1;
    }
};
//O(N)
