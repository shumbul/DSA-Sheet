class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return targetSum==root->val;
        return (hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val)); 
    }
};
//TC O(N)
//SC O(N)
