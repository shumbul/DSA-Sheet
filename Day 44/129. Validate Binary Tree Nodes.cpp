class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = -1;
        //int n = leftChild.size();
        unordered_set<int> visited;
        vector<int> indegree(n, 0); //to count how many times a node is pointed to (should be<=1)
        queue<int> nodes; //for BFS traversal starting from root
        for (int i = 0; i < n; i++) {
            if (i==leftChild[i] || i==rightChild[i]) //self loop
                return false;
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        } //For a valid tree, each node should have at most one parent
        for (int i=0;i<n;i++) {
            if (indegree[i] == 0 && root == -1) 
                root = i;
            else if (indegree[i] == 0 && root != -1) //only one root is possible
                return false;
            else if (indegree[i] >= 2) //a node cant have more than one parent
                return false;
        }
        if (root==-1) //no root
            return false;
        nodes.push(root);
        // BFS
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            if (visited.find(node) == visited.end())
                visited.insert(node); 
            else
                return false;
            if (leftChild[node] != -1) //push valid children
                nodes.push(leftChild[node]);
            if (rightChild[node] != -1)
                nodes.push(rightChild[node]);
        }
        return visited.size()==n; //all nodes should be visited else it means it is disconnected somewhere
    }
};
//TC O(N)
