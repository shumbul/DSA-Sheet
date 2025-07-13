class Solution {
    int ans=INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int depth=1; //root counts as the first level
        dfs(root, depth);
        return ans;
    }
    void dfs(TreeNode* root, int depth)
    {
        if (!root)
            return; //This check prevents exploring invalid branches
        if (!root->left && !root->right)
        {
            ans=min(ans, depth);
        }
        dfs(root->left, 1+depth); //Increase the depth by 1 as we go down a level.
        dfs(root->right, 1+depth);
    }
};
//TC O(N)
//SC O(H)
