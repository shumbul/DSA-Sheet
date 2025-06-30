class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left && !root->right)
            return false;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* node1, TreeNode* node2) //check if they are mirror images of each other
    {
           if ((node1 && !node2) || (!node1 && node2))
            return false;
        if (!node1 && !node2)
            return true;
        if (node1->val!=node2->val)
            return false;
     
        bool ans1=helper(node1->left, node2->right);
        bool ans2=helper(node2->left, node1->right);
        return (ans1 && ans2);
    }
};
//TC O(N)
//SC O(N)
