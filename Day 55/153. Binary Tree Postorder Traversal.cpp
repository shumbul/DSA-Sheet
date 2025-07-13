class Solution {
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};
