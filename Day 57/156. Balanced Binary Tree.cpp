class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true; //empty tree is balanced
        int leftdepth=height(root->left);
        int rightdepth=height(root->right);
        return abs(leftdepth-rightdepth)<=1 && (isBalanced(root->left) && isBalanced(root->right));
    }
    int height(TreeNode* node)
    {
        if (!node)
            return 0;
        return 1+max(height(node->left), height(node->right));
    }
};
//TC: O(nlogn) for balanced, O(n^2) for unbalanced
//SC: O(h)
