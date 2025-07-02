class Solution {
    unordered_map<Node*, Node*> mp;
    //original, copied
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        auto temp=node;
        if (mp.find(node)==mp.end())
        { //If the node hasn't been cloned yet
            mp[node]=new Node(node->val);
            auto clone=mp[node];
            for (auto i:node->neighbors)
            { //clone all neighbors and add them to the neighbors list of the cloned node
                clone->neighbors.push_back(cloneGraph(i));
            }
        }
        return mp[node];
    }
};
//TC O(V+E)
//SC O(E)
