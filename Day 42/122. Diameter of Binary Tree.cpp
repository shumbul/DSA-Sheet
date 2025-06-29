class Solution {
    int maxm=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxm;
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        maxm=max(maxm , left+right); //at each node, the longest path passing through it is left + right
        return 1+max(left, right); //current node itself adds one more level of depth
    }
};
