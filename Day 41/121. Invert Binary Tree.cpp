class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
       // if (root->left && root->right)
        swap(root->left, root->right);
        invertTree( root->left);
        invertTree(root->right);
        return root;
    }
};
