class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
    TreeNode* dfs(TreeNode* root, int low, int high)
    {
        if (!root)
            return nullptr;
        root->left=dfs(root->left, low, high);
        root->right=dfs(root->right, low, high);
        if (root->val>high)
            return root->left; //leaves root and connects root->left
        if (root->val<low)
            return root->right; //leaves root and connects root->right
        return root;
    }
};
