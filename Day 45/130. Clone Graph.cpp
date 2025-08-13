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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // If the given graph is empty, return null
        if (!node)
            return nullptr;
        // Queue for BFS traversal of the graph
        queue<Node*> nodes;
        nodes.push(node);
        // Map to store the mapping between original node and its cloned node
        // Key: pointer to original node
        // Value: pointer to cloned node
        unordered_map<Node*, Node*> orders;
        // Create the first cloned node (copy of the starting node)
        Node* clonenode = new Node(node->val);
        // Store mapping from original starting node to cloned node
        orders[node] = clonenode;
        // BFS traversal
        while (!nodes.empty()) {
            int sizee = nodes.size(); // Number of nodes at this BFS level
            while (sizee--) { // Process all nodes in current level
                auto frontt = nodes.front(); // Get the first node from queue
                nodes.pop();
                // Iterate through all neighbors of the current node
                for (Node* i : frontt->neighbors) {
                    // If this neighbor hasn't been cloned yet
                    if (orders.find(i) == orders.end()) {
                        // Push the original neighbor into queue for BFS
                        nodes.push(i);
                        // Create a new cloned node for this neighbor
                        Node* child = new Node();
                        child->val = i->val;
                        // Store mapping from original neighbor to cloned neighbor
                        orders[i] = child;
                    }
                    // Link the cloned neighbor to the cloned current node's neighbors list
                    orders[frontt]->neighbors.push_back(orders[i]);
                }
            }
        }
        // Return the cloned starting node (entire cloned graph is connected from here)
        return orders[node];
    }
};
