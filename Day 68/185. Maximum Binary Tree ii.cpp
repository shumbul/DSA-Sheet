class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root->val<val)
        {
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        else
        {
            if (root->right)
                root->right=insertIntoMaxTree(root->right, val);
            else
                root->right=new TreeNode(val);
        }
        return root;
    }
};
