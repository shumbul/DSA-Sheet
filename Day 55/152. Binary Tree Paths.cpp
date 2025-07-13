class Solution {
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root, string path="") { //accumulate the path as we traverse.
        if (!root)
            return {};
         path+=to_string(root->val); //append the current node's value
        if (!root->left && !root->right)
        {
            ans.push_back(path);
        }
       else
            path+="->"; //If it’s not a leaf, we’re still building the path
        binaryTreePaths(root->left, path);
        binaryTreePaths(root->right, path);
        return ans;
    }
};
/* TC: O(n * L)
n = number of nodes in the tree
L = average length of each path (depth of tree in worst case)
SC: O(h + k * L)
h = height of the tree → recursion call stack
k = number of leaf nodes (i.e., number of paths)
L = average path length (max height of the tree)
*/
